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
const int N = 1e5 + 5;

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
int prime[N] = {0};
vi p;
void sieve()
{
    p.push_back(2);
    for (int i = 4; i < N; i += 2)
        prime[i] = 1;
    for (int i = 3; i < N; i += 2)
    {
        if (prime[i] == 0)
        {
            p.push_back(i);
            for (int j = i * i; j < N; j += i + i)
            {
                prime[j] = i;
            }
        }
    }
}
void solve()
{
    int a, b, k;
    cin >> a >> b >> k;

    if (k == 1)
    {
        if (a == b)
            no;
        else if (a % b == 0 || b % a == 0)
            yes;
        else
            no;
        return;
    }

    int x = 0;
    for (auto u : p)
    {
        while (a % u == 0)
        {
            a /= u;
            x++;
            if (x >= k)
            {
                yes;
                return;
            }
        }
        if (u > a)
            break;
    }
    if (a > 1)
        x++;
    for (auto u : p)
    {
        while (b % u == 0)
        {
            b /= u;
            x++;
            if (x >= k)
            {
                yes;
                return;
            }
        }
        if (u > b)
            break;
    }
    if (b > 1)
        x++;
    if (x >= k)
    {
        yes;
        return;
    }
    no;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}