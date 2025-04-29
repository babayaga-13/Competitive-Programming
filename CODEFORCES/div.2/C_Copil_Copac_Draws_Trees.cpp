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
vector<vector<pair<int, int>>> v;
vector<int> a, vis;

int dfs(int x, int y)
{
    int s = 0;
    vis[x] = 1;
    for (auto [c, d] : v[x])
    {
        if (!vis[c])
        {
            if (d < y)
            {
                s = max(s, 1 + dfs(c, d));
            }
            else
                s = max(s, dfs(c, d));
        }
    }
    return s;
}
void solve()
{
    // v.clear();
    // vis.clear();
    // int n;
    // cin >> n;
    // v.assign(n + 1, {});
    // vis.assign(n + 1, 0);
    v.clear();
    vis.clear();
    int n;
    cin >> n;
    v.resize(n + 1);
    vis.resize(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }

    cout << dfs(1, 0) + 1 << endl;
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