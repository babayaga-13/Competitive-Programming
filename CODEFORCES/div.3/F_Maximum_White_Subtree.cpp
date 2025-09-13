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
#define count_one(x) __builtin_popcountll(x)
#define trailing_zero(x) __builtin_ctzll(x)
#define leading_zero(x) __builtin_clzll(x)
#define gcd __gcd
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ((__int128_t)ans * a) % MOD, n--;
        a = ((__int128_t)a * a) % MOD, n >>= 1;
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
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 1; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}
int nCr(int n, int r)
{
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
long long nPr(int n, int r)
{
    return fact[n] * inv_fact[n - r] % MOD;
}

vi a, dp, ans;
vii adj;

void dfs(int c, int p)
{
    for (auto u : adj[c])
    {
        if (u == p)
            continue;
        dfs(u, c);
        dp[c] += max(dp[u], 0LL);
    }
}

void rdfs(int c, int p)
{
    for (auto u : adj[c])
    {
        if (u == p)
            continue;
        ans[u] = max(dp[u], dp[u] + ans[c] - max(0LL, dp[u]));
        rdfs(u, c);
    }
}

void solve()
{
    int n;
    cin >> n;
    dp.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    adj.assign(n + 1, {});

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!x)
            dp[i] = -1;
        else
            dp[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    ans[1] = dp[1];
    rdfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
