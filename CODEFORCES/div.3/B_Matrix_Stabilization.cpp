#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = 0;
                if (i != (n - 1))
                {
                    if (a[i][j] > a[i + 1][j])
                        x = max(x, a[i + 1][j]);
                    else
                        continue;
                }
                if (i != 0)
                {
                    if (a[i][j] > a[i - 1][j])
                        x = max(x, a[i - 1][j]);
                    else
                        continue;
                }
                if (j != 0)
                {
                    if (a[i][j] > a[i][j - 1])
                        x = max(x, a[i][j - 1]);
                    else
                        continue;
                }
                if (j != (m - 1))
                {
                    if (a[i][j] > a[i][j + 1])
                        x = max(x, a[i][j + 1]);
                    else
                        continue;
                }
                a[i][j] = x;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}