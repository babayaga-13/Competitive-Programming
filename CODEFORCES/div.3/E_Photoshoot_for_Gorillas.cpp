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
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++)
        cin >> a[i];
    vector<int> v;
    v.reserve(n * m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int i1 = max(1, i - k + 1);
            int j1 = max(1, j - k + 1);
            int i2 = min(i, n - k + 1);
            int j2 = min(j, m - k + 1);
            v.push_back((i2 - i1 + 1) * (j2 - j1 + 1));
        }
    }
    sort(v.rbegin(), v.rend());
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (int i = 0; i < w; i++)
    {
        ans += 1LL * a[i] * v[i];
    }
    cout << ans << '\n';
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
