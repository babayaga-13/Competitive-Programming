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
    ll n, ans = 0;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(v.rbegin(), v.rend());
    vector<ll> a(n);
    ll c = 1;
    for (int i = 0; i < n; i++)
    {
        ans += (2 * abs(c) * v[i].first);
        a[v[i].second] = c;
        if (c > 0)
            c *= -1;
        else
        {
            c *= -1;
            c++;
        }
    }
    cout << ans << "\n0 ";
    for (auto u : a)
        cout << u << " ";
    ln;
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
