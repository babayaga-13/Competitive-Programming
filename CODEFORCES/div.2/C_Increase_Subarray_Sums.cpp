#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << "\n"
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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<ll> mx(n + 1, LLONG_MIN);
        mx[0] = 0;
        for (int i = 0; i < n; i++)
        {
            ll s = 0;
            for (int j = i; j < n; j++)
            {
                s += a[j];
                mx[j - i + 1] = max(mx[j - i + 1], s);
            }
        }
        for (int i = 0; i <= n; i++)
        {
            ll ans = 0;
            for (int j = 0; j <= n; j++)
            {
                ans = max(ans, mx[j] + min(j, i) * x);
            }
            cout << ans << " ";
        }
        ln;
    }

    return 0;
}
