#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
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
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int m;
        cin >> m;
        int b[m + 1];
        a[0] = 0, b[0] = 0;
        for (int i = 1; i <= m; i++)
            cin >> b[i];

        for (int i = 2; i <= n; i++)
            a[i] += a[i - 1];

        for (int i = 2; i <= m; i++)
            b[i] += b[i - 1];
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                ans = max(ans, a[i] + b[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
