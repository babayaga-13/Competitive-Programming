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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    vector<ll> u, v;
    u.push_back(1);
    v.push_back(1);

    ll z = 1;
    while (z <= (1e18 / x) && z + 1 <= b)
    {
        z *= x;
        u.push_back(z);
    }
    z = 1;
    while (z <= (1e18 / y) && z + 1 <= b)
    {
        z *= y;
        v.push_back(z);
    }
    set<ll> w;
    for (auto m : u)
    {
        for (auto n : v)
        {
            if (m + n >= a && m + n <= b)
            {
                w.insert(m + n);
            }
        }
    }
    if (w.empty())
    {
        cout << b - a + 1;
        return;
    }
    ll c = *w.begin();
    ll ans = c - a;

    for (auto m : w)
    {
        ans = max(ans, m - c - 1);
        c = m;
    }
    ans = max(ans, b - c);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}