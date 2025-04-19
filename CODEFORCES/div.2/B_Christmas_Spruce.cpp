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
using namespace std;

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

vector<vector<int>> v;
map<int, int> mp;
void dfs(int x)
{
    int c = 0;
    for (auto u : v[x])
    {
        if (v[u].empty())
            c++;
        dfs(u);
    }
    if (!v[x].empty())
    {
        mp[x] = c;
    }
}

void solve()
{
    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    for (auto [a, b] : mp)
    {
        if (b < 3)
        {
            no;
            return;
        }
    }
    yes;
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