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
        int n, m;
        cin >> n >> m;
        int a[n * m + 1];
        for (int i = 1; i <= n * m; i++)
            cin >> a[i];

        int j = n * m - (n / 2);
        ll ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans += a[j];
            // cout << a[j] << " ";
            j -= (n / 2) + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
