#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define count_one(x) __builtin_popcount(x)
#define trailing_zero(x) __builtin_ctz(x)
#define leading_zero(x) __builtin_clz(x)
#define gcd __gcd
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;

ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
        {
            ans = (ans * a) % MOD;
            n--;
        }
        else
        {
            a = (a * a) % MOD;
            n /= 2;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    ll s = 0, ss = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        s = (s + x) % MOD;
        ss = (ss + (x * x) % MOD) % MOD;
    }

    ll p = (1LL * n * (n - 1) / 2) % MOD;
    ll inv_p = power(p, MOD - 2);
    ll tot = (s * s % MOD - ss + MOD) % MOD;
    ll ans = (tot * power(2, MOD - 2) % MOD) * inv_p % MOD;
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}