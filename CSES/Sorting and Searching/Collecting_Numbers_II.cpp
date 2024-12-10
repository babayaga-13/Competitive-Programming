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
    ll n, q;
    cin >> n >> q;
    ll a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i] > b[i + 1])
            ans++;
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll p = a[x], q = a[y];
        if (p != 1 && b[p] < b[p - 1])
            ans--;
        if (p != n && b[p] > b[p + 1])
            ans--;
        if (q != 1 && q - 1 != p && b[q] < b[q - 1])
            ans--;
        if (q != n && q + 1 != p && b[q] > b[q + 1])
            ans--;

        b[p] = y;
        b[q] = x;
        swap(a[x], a[y]);

        if (p != 1 && b[p] < b[p - 1])
            ans++;
        if (p != n && b[p] > b[p + 1])
            ans++;
        if (q != 1 && q - 1 != p && b[q] < b[q - 1])
            ans++;
        if (q != n && q + 1 != p && b[q] > b[q + 1])
            ans++;

        cout << ans << endl;
    }
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
}