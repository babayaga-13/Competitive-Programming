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
    ll n, l, h, k, ans = 0;
    cin >> n >> l >> h >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < (1 << n); i++)
    {
        ll x = 0;
        ll mx = 0, mn = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                x += a[j];
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
            }
        }
        if (x >= l && x <= h && (mx - mn) >= k)
            ans++;
    }
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