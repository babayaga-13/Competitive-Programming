#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pi <int,int>
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
const int N = 2e5 + 5;


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

vi vis(N, 0), a(N, 0), b(N, 0);
vector<int> adj[N + 1];
int c = 0;
void dfs(int p)
{
    vis[p] = 1;
    for (auto u : adj[p])
    {
        if (!vis[u])
        {
            a[u] = a[p] + 1;
            dfs(u);
        }
    }
}
void dfs1(int p)
{
    vis[p] = 1;
    for (auto u : adj[p])
    {
        if (!vis[u])
        {
            b[u] = b[p] + 1;
            dfs(u);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int x = max_element(all(a)) - a.begin();
    a.assign(N, 0);
    vis.assign(N, 0);
    dfs(x);
    int y = max_element(all(a)) - a.begin();
    vis.assign(N, 0);
    dfs1(y);
    for (int i = 1; i <= n; i++)
        cout << max(a[i], b[i]) << " ";
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