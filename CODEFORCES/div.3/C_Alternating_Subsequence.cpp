#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        ll sum = 0;
        int x = 0, y = 0;

        for (int i = 0; i < n; ++i)
        {
            if (v[i] < 0)
            {
                if (x == 0)
                {
                    x = v[i];
                }
                else
                {
                    x = max(x, v[i]);
                }
                if (i == n - 1 || v[i + 1] >= 0)
                {
                    sum += x;
                    x = 0;
                }
            }
            else if (v[i] > 0)
            {
                if (y == 0)
                {
                    y = v[i];
                }
                else
                {
                    y = max(y, v[i]);
                }
                if (i == n - 1 || v[i + 1] <= 0)
                {
                    sum += y;
                    y = 0;
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}
