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
        int n, m;
        cin >> n >> m;

        int a[n + 1][m + 1];

        int c = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = c;
                c++;
            }
        }

        for (int i = 2; i <= n; i += 2)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 1; i <= n; i += 2)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
