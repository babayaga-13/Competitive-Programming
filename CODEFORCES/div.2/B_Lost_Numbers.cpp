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
int q(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
    fflush(stdout);
}
int b[6] = {4, 8, 15, 16, 23, 42};
void solve()
{
    int a[7];
    map<int, int> mp;
    for (int i = 0; i < 6; i++)
        mp[b[i]]++;
    int f1 = q(1, 2);
    int f2 = q(2, 3);
    for (int i = 0; i < 6; i++)
    {
        if (f1 % b[i] == 0 && f2 % b[i] == 0 && (f1 / b[i] != f2 / b[i]) && mp[f1 / b[i]] && mp[f2 / b[i]] && f1 / b[i] != b[i] && f2 / b[i] != b[i] && f1 / b[i] != f2 / b[i])
        {
            a[2] = b[i];
            a[1] = f1 / b[i];
            a[3] = f2 / b[i];
            break;
        }
    }
    f1 = q(4, 5);
    f2 = q(5, 6);
    for (int i = 0; i < 6; i++)
    {
        if (f1 % b[i] == 0 && f2 % b[i] == 0 && (f1 / b[i] != f2 / b[i]) && mp[f1 / b[i]] && mp[f2 / b[i]] && f1 / b[i] != b[i] && f2 / b[i] != b[i] && f1 / b[i] != f2 / b[i])
        {
            a[5] = b[i];
            a[4] = f1 / b[i];
            a[6] = f2 / b[i];
            break;
        }
    }
    cout << "! ";
    for (int i = 1; i < 7; i++)
        cout << a[i] << " ";
}

signed main()
{

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}