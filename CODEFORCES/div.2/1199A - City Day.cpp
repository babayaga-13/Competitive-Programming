#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;

        for (int j = 1; j <= x; j++)
        {
            if (i - j < 0)
                break;
            if (v[i] >= v[i - j])
            {
                flag = false;
                break;
            }
        }

        for (int j = 1; j <= y; j++)
        {
            if (i + j >= n)
                break;
            if (v[i] >= v[i + j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << i + 1;
            break;
        }
    }

    return 0;
}
