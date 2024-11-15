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

const int N = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = ((__int128_t)ans * a) % N, n--;
        a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, m, c = 0;
    cin >> n >> m;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        c += a[i];
    }

    if (c < m)
    {
        cout << "-1\n";
        return;
    }
    else if (c == m)
    {
        cout << "0\n";
        return;
    }
    vector<ll> pre(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i - 1];
        // cout << pre[i] << " ";
    }
    ll ans = INT_MAX;
    for (ll i = 1; i <= n; i++)
    {
        ll target = pre[i - 1] + m;
        if (target > c)
            break;
        ll x = upper_bound(all(pre), target) - pre.begin();
        ll y = (n - x) + (i);
        ans = min(ans, y);
    }

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