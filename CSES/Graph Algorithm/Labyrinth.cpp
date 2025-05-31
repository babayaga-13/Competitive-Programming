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
int n, m, s1, s2, e1, e2;
char adj[1005][10005];
bool vis[1005][10005] = {};
pair<int, int> p[1005][10005] = {};

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool check(int x, int y)
{
    if (x < 0 || y < 0 || x > n - 1 || y > m - 1 || adj[x][y] == '#' || vis[x][y])
        return false;
    return true;
}
bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;

    while (!q.empty())
    {
        auto [l, r] = q.front();
        q.pop();

        if (adj[l][r] == 'B')
            return true;

        for (int i = 0; i < 4; i++)
        {
            int nx = l + dir[i][0], ny = r + dir[i][1];
            if (check(nx, ny))
            {
                vis[nx][ny] = 1;
                p[nx][ny] = {l, r};
                q.push({nx, ny});
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'A')
            {
                s1 = i, s2 = j;
            }
            if (adj[i][j] == 'B')
            {
                e1 = i, e2 = j;
            }
        }
    }
    if (bfs(s1, s2))
    {
        yes;
        string s;
        while (e1 != s1 || e2 != s2)
        {
            auto [u, v] = p[e1][e2];
            for (int i = 0; i < 4; i++)
            {
                if (u + dir[i][0] == e1 && v + dir[i][1] == e2)
                {
                    if (i == 0)
                        s += 'R';
                    else if (i == 1)
                        s += 'D';
                    else if (i == 2)
                        s += 'L';
                    else if (i == 3)
                        s += 'U';

                    e1 = u, e2 = v;
                    break;
                }
            }
        }
        reverse(all(s));
        cout << s.size() << endl
             << s << endl;
    }
    else
        no;
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