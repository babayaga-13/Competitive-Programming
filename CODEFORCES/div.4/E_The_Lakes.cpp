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
int n, m;
int a[1001][1001];
bool vis[1001][1001] = {false};
int dfs(int i, int j)
{
    vis[i][j] = true;
    int s = a[i][j];
    if (i != 0 && a[i - 1][j] != 0 && !vis[i - 1][j])
        s += dfs(i - 1, j);
    if (i != n - 1 && a[i + 1][j] != 0 && !vis[i + 1][j])
        s += dfs(i + 1, j);
    if (j != 0 && a[i][j - 1] != 0 && !vis[i][j - 1])
        s += dfs(i, j - 1);
    if (j != m - 1 && a[i][j + 1] != 0 && !vis[i][j + 1])
        s += dfs(i, j + 1);
    return s;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            vis[i][j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != 0 && !vis[i][j])
                ans = max(ans, dfs(i, j));
        }
    }
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