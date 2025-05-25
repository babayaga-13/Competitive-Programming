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

int n;
vector<vector<char>> v;
vector<vector<bool>> vis;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool check(int x, int y)
{
    return x >= 0 && x < 2 && y >= 0 && y < n;
}
bool dfs(int x, int y)
{
    if (x == 1 && y == n - 1)
        return true;
    vis[x][y] = true;
    for (auto [dx, dy] : dir)
    {
        int nx = x + dx, ny = y + dy;
        if (!check(nx, ny))
            continue;
        if (v[nx][ny] == '>')
            ny++;
        else if (v[nx][ny] == '<')
            ny--;
        if (check(nx, ny) && !vis[nx][ny])
        {
            if (dfs(nx, ny))
                return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    v.assign(2, vector<char>(n));
    for (int i = 0; i < n; i++)
        cin >> v[0][i];
    for (int i = 0; i < n; i++)
        cin >> v[1][i];

    vis.assign(2, vector<bool>(n, false));
    if (dfs(0, 0))
        yes;
    else
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