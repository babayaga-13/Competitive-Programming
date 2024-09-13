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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 2;
        ll m = 0;
        for (ll x = 2; x <= n; ++x)
        {
            ll k = n / x;
            k = (k * (k + 1)) / 2;
            ll s = x * k;
            if (s > m)
            {
                ans = x;
                m = s;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
