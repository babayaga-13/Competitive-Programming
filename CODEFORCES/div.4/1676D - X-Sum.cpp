#include <bits/stdc++.h>
#define ll long long
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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = i, y = j;
                int ans = 0;
                while (x >= 0 && y >= 0)
                {
                    ans += a[x][y];
                    x--;
                    y--;
                }
                x = i;
                y = j;
                while (x >= 0 && y < m)
                {
                    ans += a[x][y];
                    x--;
                    y++;
                }
                x = i;
                y = j;
                while (x < n && y < m)
                {
                    ans += a[x][y];
                    x++;
                    y++;
                }
                x = i;
                y = j;
                while (x < n && y >= 0)
                {
                    ans += a[x][y];
                    x++;
                    y--;
                }
                x = i;
                y = j;
                ans -= 3 * a[x][y];
                mx = max(mx, ans);
            }
        }
        cout << mx << endl;
    }
    return 0;
}
