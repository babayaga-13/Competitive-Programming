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
vector<pi> pre;
pair<int, vector<int>> ans(int target)
{
    vector<int> dp1(target + 1, INT_MAX);
    vector<pair<int, int>> last(target + 1, {-1, -1});
    dp1[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (auto [u, v] : pre)
        {
            if (u <= i && dp1[i - u] != INT_MAX && dp1[i - u] + v < dp1[i])
            {
                dp1[i] = dp1[i - u] + v;
                last[i] = {u, v};
            }
        }
    }
    vi used;
    int curr = target;
    while (curr > 0 && last[curr].first != -1)
    {
        used.push_back(last[curr].second);
        curr -= last[curr].first;
    }
    return {dp1[target], used};
}

void solve()
{
    int n, k;
    cin >> n >> k;
    pair<int, vector<int>> v;
    v = ans((n * (n - 1)) / 2 - k);

    if (v.first > n)
    {
        cout << "0\n";
    }
    else
    {
        int i = 1, j = n;
        for (auto u : v.second)
        {
            j = j - u;
            for (int k = 1; k <= u; k++)
                cout << j + k << " ";
        }
        for (int k = j; k >= i; k--)
            cout << k << " ";
        ln;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 2; i <= 30; i++)
    {
        pre.push_back({(i * (i - 1)) / 2, i});
    }
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}