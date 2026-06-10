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
    ll cnt = 1;
    while (n)
    {
        if (n % 2)
            cnt = ((__int128_t)cnt * a) % MOD, n--;
        a = ((__int128_t)a * a) % MOD, n /= 2;
    }
    return cnt;
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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    int curr = 0;
    for (int i = 1; i < n; i++)
    {
        int c = a[0];
        if (a[0] % 2)
            c++;
        while ((a[i] + 1) / 2 > c)
        {
            if (a[i] % 2)
            {
                a[i]++;
            }
            else
            {
                a[i] /= 2;
            }
            curr++;
        }
    }
    unordered_map<int, int> mp, cnt;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        mp[a[i]]++;
        if (a[i] == 1)
        {
            mp[a[i] + 1]++;
            cnt[a[i] + 1] += 1;
        }
        while (a[i] > 1)
        {
            if (a[i] % 2)
            {
                a[i]++;
            }
            else
            {
                a[i] /= 2;
            }
            c++;
            mp[a[i]]++;
            cnt[a[i]] += c;
        }
    }
    int ans = 1e18;
    for (auto [u, v] : mp)
    {
        if (v == n)
        {
            ans = min(ans, cnt[u]);
        }
    }
    cout << ans + curr << endl;
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