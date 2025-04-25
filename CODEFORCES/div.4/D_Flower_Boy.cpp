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

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    vector<ll> pre(m, -1), suf(m, -1);

    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < m; ++i)
        cin >> b[i];

    ll x = 0;
    for (ll i = 0; i < n && x < m; i++)
    {
        if (a[i] >= b[x])
        {
            pre[x] = i;
            x++;
        }
    }
    if (pre[m - 1] != -1)
    {
        cout << 0 << '\n';
        return;
    }

    x = m - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (x >= 0 && a[i] >= b[x])
        {
            suf[x] = i;
            x--;
        }
    }

    ll ans = INT_MAX;
    bool f = false;
    for (ll i = 0; i < m; i++)
    {

        if (i - 1 >= 0 && pre[i - 1] == -1)
            continue;
        if (i + 1 < m && suf[i + 1] == -1)
            continue;
        if (i - 1 >= 0 && i + 1 < m && pre[i - 1] >= suf[i + 1])
            continue;
        ans = min(ans, b[i]);
        f = true;
    }
    if (f)
        cout << ans << '\n';
    else
        cout << "-1\n";
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