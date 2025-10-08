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

const int MOD = 998244353;
const int N = 1000005;

ll power(ll a, ll n)
{
    ll ans = 1;
    a %= MOD;
    while (n)
    {
        if (n & 1)
            ans = (__int128)ans * a % MOD, n--;
        a = (__int128)a * a % MOD;
        n >>= 1;
    }
    return ans;
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
    if (r < 0 || r > n || n < 0)
        return 0;
    return (int)(fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n - r] % MOD);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        pre[i] = nCr(2 * n - i - 1, n - 1) % MOD;
        if (i > 0)
            pre[i] = (pre[i] + pre[i - 1]) % MOD;
    }

    vector<int> pre1(n, 0);
    for (int i = 0; i <= n - 1; i++)
    {
        pre1[i] = (nCr((n - 1) + i, n - 1)) % MOD;
        if (i > 0)
            pre1[i] = (pre1[i] + pre1[i - 1]) % MOD;
    }

    for (int i = 1; i <= n; ++i)
    {
        int ans = (pre[i] - pre1[i - 1] + MOD) % MOD;
        cout << ans << " ";
    }
    ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init_fact();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
