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
        else
            a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, d, k;
    cin >> n >> d >> k;
    vector<int> v1(n + 1, 0), v2(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        ll l, r;
        cin >> l >> r;
        v1[l]++, v2[r]++;
    }
    for (int i = 1; i <= n; i++)
    {
        v1[i] += v1[i - 1];
        v2[i] += v2[i - 1];
    }
    ll ans1 = 0, ans2 = 0, mx = 0, mn = 1e9;
    for (int i = 1; i <= n - d + 1; i++)
    {
        ll c = v1[i + d - 1] - v2[i - 1];
        if (mx < c)
            mx = c, ans1 = i;
        if (mn > c)
            mn = c, ans2 = i;
    }
    cout << ans1 << ' ' << ans2 << endl;
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