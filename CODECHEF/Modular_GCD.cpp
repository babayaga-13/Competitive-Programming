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
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll x, ll a, ll mod)
{
    ll r = 1;
    while (a > 0)
    {
        if (a % 2 == 1)
        {
            r = ((__int128_t)r * x) % mod;
        }
        a /= 2;
        x = ((__int128_t)x * x) % mod;
    }
    return r;
}

void solve()
{
    int N = 1e9 + 7;
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = abs(a - b);
    if (x == 0)
    {
        ll ans = (power(a, n, N) + power(b, n, N)) % N;
        cout << ans << endl;
        return;
    }
    ll aa = power(a, n, x);
    ll bb = power(b, n, x);
    ll gcd_result = gcd((aa + bb) % x, x);
    cout << gcd_result % N << endl;
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