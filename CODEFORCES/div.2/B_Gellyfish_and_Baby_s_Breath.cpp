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

const int MOD = 998244353;
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
    return ans % MOD;
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

void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n), l(n), r(n);
    int x = -1;
    vector<pair<int, int>> u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > x)
        {
            x = a[i];
            u.emplace_back(x, i);
        }
        else
        {
            auto [c, d] = u.back();
            u.emplace_back(c, d);
        }
    }
    x = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] > x)
        {
            x = b[i];
            v.emplace_back(x, i);
        }
        else
        {
            auto [c, d] = v.back();
            v.emplace_back(c, d);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int s;
        if (a[u[i].second] > b[v[i].second] || (a[u[i].second] == b[v[i].second] && b[i - u[i].second] > a[i - v[i].second]))
            s = (power(2, a[u[i].second]) + power(2, b[i - u[i].second])) % MOD;
        else
            s = (power(2, b[v[i].second]) + power(2, a[i - v[i].second])) % MOD;
        cout << s << " ";
    }
    ln;
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