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
vii a, b, c;
void solve()
{
    string s;
    cin >> s;
    int i, j;
    cin >> i >> j;
    if (s.size() == 2)
    {
        vi x = a[i], y = a[j];

    }
    if (s.size() == 3)
    {
        vi x = a[i], y = a[j];
    }
    if (s.size() == 4)
    {
        vi x = a[i], y = a[j];
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi v;
    v.push_back(1);
    for (int i = 2; i < 5; i++)
    {
        v.push_back(2);
        if (i == 2)
        {
            vi x = v;
            a.push_back(x);
            while (next_permutation(all(x)))
            {
                a.push_back(x);
            }
        }
        if (i == 3)
        {
            vi x = v;
            b.push_back(x);
            while (next_permutation(all(x)))
            {
                b.push_back(x);
            }
        }
        if (i == 4)
        {
            vi x = v;
            c.push_back(x);
            while (next_permutation(all(x)))
            {
                c.push_back(x);
            }
        }
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}