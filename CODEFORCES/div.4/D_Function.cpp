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
const int mod = 1e9 + 7;
ll solve(ll x, ll y)
{
    ll result = 1;
    x %= mod;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
        {
            result = (result * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll l, h, k;
        cin >> l >> h >> k;

        if (k >= 10)
        {
            cout << 0 << endl;
            continue;
        }

        ll m = 10 / k;
        if (10 % k)
        {
            m++;
        }
        ll x = solve(m, h);
        ll y = solve(m, l);
        ll ans = (x - y + mod) % mod;

        cout << ans << endl;
    }
    return 0;
}
