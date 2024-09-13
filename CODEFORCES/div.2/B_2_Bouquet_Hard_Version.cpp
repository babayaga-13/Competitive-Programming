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

const int N = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = (ans * a) % N, n--;
        else
            a = (a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> c(n);
    map<ll, ll> mp;
    ll ans = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
        mp[a[i]] += c[i];
    }

    for (auto u : mp)
    {
        ll x = u.first;
        ll y = u.second;
        ans = max(ans, min(m / x, y) * x);

        if (mp.find(x + 1) == mp.end())
            continue;

        ll y1 = mp[x + 1];
        ll k1 = min(m / x, y);
        ll sum = x * k1;
        y -= k1;
        ll coins = m - sum;
        if (coins >= x + 1)
        {
            ll k2 = min(coins / (x + 1), y1);
            sum += k2 * (x + 1);
            y1 -= k2;
            coins = m - sum;
        }
        sum += min({coins, y1, k1});
        ans = max(sum, ans);
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
