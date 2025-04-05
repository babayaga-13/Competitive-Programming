#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

int main()
{
    int n;
    cin >> n;
    int a[n][2];
    for (int k = 0; k < 2; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i][k];
        }
    }

    int ans = INF;

    for (int j = 1; j < n - 1; ++j)
    {
        int left_min = INF;
        // Find the minimal cost in the left part (i < j) where a[i][0] < a[j][0]
        for (int i = 0; i < j; ++i)
        {
            if (a[i][0] < a[j][0])
            {
                if (a[i][1] < left_min)
                {
                    left_min = a[i][1];
                }
            }
        }
        if (left_min == INF)
            continue;

        int right_min = INF;
        // Find the minimal cost in the right part (k > j) where a[k][0] > a[j][0]
        for (int k = j + 1; k < n; ++k)
        {
            if (a[k][0] > a[j][0])
            {
                if (a[k][1] < right_min)
                {
                    right_min = a[k][1];
                }
            }
        }
        if (right_min == INF)
            continue;

        int total = left_min + a[j][1] + right_min;
        if (total < ans)
        {
            ans = total;
        }
    }

    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}