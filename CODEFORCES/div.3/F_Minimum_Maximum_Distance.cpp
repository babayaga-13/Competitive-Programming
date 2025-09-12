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
int n, k;
vi a(N, 0), sz(N, 0);
vector<vector<int>> adj;
void dfs1(int c, int p)
{
    for (auto u : adj[c])
    {
        if (u != p)
        {
            a[u] = a[c] + 1;
            dfs1(u, c);
        }
    }
}

void solve()
{

    cin >> n >> k;
    adj.assign(n + 1, {});
    a.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        sz[x] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1, 0);
    int c = 0, x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > c && sz[i] == 1)
        {
            c = max(c, a[i]);
            x = i;
        }
    }
    a.assign(n + 1, 0);
    dfs1(x, 0);
    c = 0, x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > c && sz[i] == 1)
        {
            c = max(c, a[i]);
            x = i;
        }
    }

    cout << (c + 1) / 2 << endl;
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