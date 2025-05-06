#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = ((__int128_t)ans * a) % MOD, n--;
        a = ((__int128_t)a * a) % MOD, n /= 2;
    }
    return ans;
}
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
vector<ll> v;
bool check(ll l, ll r)
{
    ll s = 0, y;

    cout << "? " << r - l + 1 << " ";
    for (ll i = l; i <= r; i++)
    {
        cout << i << " ";
        s += v[i];
    }
    cout.flush();
    cin >> y;
    return s + 1 == y;
}
void solve()
{
    v.clear();
    ll n;
    cin >> n;
    v.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    ll l = 1, r = n, ans = 0;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (check(l, m))
            ans = m, r = m - 1;
        else
            l = m + 1;
    }
    cout << "! " << ans << endl;
    cout.flush();
}

signed main()
{

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}