#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vpi vector<pi>
#define vii vector<vector<int>>
#define pi pair<int, int>
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
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

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
long long fact[N], inv_fact[N];
void init_fact()
{
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 1; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}
int nCr(int n, int r)
{
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
long long nPr(int n, int r)
{
    return fact[n] * inv_fact[n - r] % MOD;
}
vii adj;
vi vis, a, b, ans;
void dfs(int x)
{
    vis[x] = 1;
    for (auto u : adj[x])
    {
        if (!vis[u])
        {
            a[u] = a[x] + 1;
            dfs(u);
            b[x] = min(b[x], b[u] + 1);
        }
    }
}
void dfs1(int x)
{
    vis[x] = 1;
    if (a[x] < b[x])
    {
        ans[x] = 1;
    }
    else
        return;
    for (auto u : adj[x])
    {
        if (!vis[u])
        {
            a[u] = a[x] + 1;
            dfs1(u);
            b[x] = min(b[x], b[u] + 1);
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    adj.clear();
    vis.clear();
    a.clear();
    b.clear();
    ans.clear();
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    a.assign(n + 1, 1e9);
    b.assign(n + 1, 1e9);
    ans.assign(n + 1, -1);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        b[x] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    a[1] = 0;
    dfs(1);
    vis.assign(n + 1, 0);
    dfs1(1);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // ln;
    // for (int i = 1; i <= n; i++)
    //     cout << b[i] << " ";
    // ln;
    // for (int i = 1; i <= n; i++)
    //     cout << ans[i] << " ";
    // ln;
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() == 1 && ans[i] == 1)
        {
            yes;
            return;
        }
    }
    no;
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