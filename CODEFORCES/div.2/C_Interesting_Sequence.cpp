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
int check(int n, int x)
{
    while (x > n)
    {
        x = (x & (x - 1));
    }
    return x & n;
}
void solve()
{

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < 63; i++)
    {
        if ((n & (1LL << i)) == 0 && (x & (1LL << i)) != 0)
        {
            cout << "-1\n";
            return;
        }
    }
    if (n == x)
    {
        cout << n << endl;
        return;
    }

    int a = -1, b = -1;
    int ans = 0;

    for (int i = 0; i < 63; i++)
    {
        if ((n & (1LL << i)) && (x & (1LL << i)))
        {
            a = i;
            break;
        }
    }
    for (int i = 62; i >= 0; i--)
    {
        if ((n & (1LL << i)) != (x & (1LL << i)))
        {
            b = i;
            break;
        }
    }
    // cout << a << " " << b << endl;
    if ((b > a && a != -1) || ((n & (1LL << (b + 1)))))
    {
        cout << "-1\n";
        return;
    }

    for (int i = 62; i > b; i--)
    {   
        if (n & (1LL << i))
            ans |= (1LL << i);
    }

    ans |= (1LL << (b + 1));

    cout << ans << endl;

    // int l = n, r = LLONG_MAX, ans = -1;
    // while (l <= r)
    // {
    //     int m = l + (r - l) / 2;
    //     int c = check(n, m);
    //     if (c == x)
    //     {
    //         ans = m;
    //         r = m - 1;
    //     }
    //     else if (c > x)
    //         l = m + 1;
    //     else
    //         r = m - 1;
    // }
    // cout << ans << endl;
    // 1010011100010010010101111110011010101010110101110111100010110111
    // 100000000000000000000000000000000000000000000000000000000000
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