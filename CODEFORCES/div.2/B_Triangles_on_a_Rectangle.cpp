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

const ll N = 1e9 + 7;
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
    ll x, y;
    cin >> x >> y;
    ll a, b, c, d;
    ll ans = 0;
    cin >> a;
    ll l1[a];
    for (ll i = 0; i < a; i++)
        cin >>
            l1[i];
    ans = max(ans, (l1[a - 1] - l1[0]) * y);

    cin >> b;
    ll l2[b];
    for (ll i = 0; i < b; i++)
        cin >> l2[i];
    ans = max(ans, (l2[b - 1] - l2[0]) * y);

    cin >> c;
    ll h1[c];
    for (ll i = 0; i < c; i++)
        cin >> h1[i];
    ans = max(ans, (h1[c - 1] - h1[0]) * x);

    cin >> d;
    ll h2[d];
    for (ll i = 0; i < d; i++)
        cin >> h2[i];
    ans = max(ans, (h2[d - 1] - h2[0]) * x);

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
