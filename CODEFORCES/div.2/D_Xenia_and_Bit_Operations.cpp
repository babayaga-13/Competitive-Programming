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
const int N = 3e5 + 9;

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

vi a;
struct ST
{
    vi t;
    ST()
    {
        t.assign(4 * N, 0);
    }
    void build(int n, int b, int e, int x)
    {
        if (b == e)
        {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid, x ^ 1);
        build(r, mid + 1, e, x ^ 1);
        if (x)
            t[n] = t[l] | t[r];
        else
            t[n] = t[l] ^ t[r];
    }
    void upd(int n, int b, int e, int i, int x, int y)
    {
        if (b > i || e < i)
            return;
        if (b == e && b == i)
        {
            t[n] = x;
            a[i] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        if (i <= mid)
            upd(l, b, mid, i, x, y ^ 1);
        else
            upd(r, mid + 1, e, i, x, y ^ 1);
        if (y)
            t[n] = t[l] | t[r];
        else
            t[n] = t[l] ^ t[r];
    }
} t;

void solve()
{
    int n, q;
    cin >> n >> q;
    a.assign((1 << n), 0);
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i];
    ST seg;
    seg.build(1, 0, (1 << n) - 1, n % 2);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        seg.upd(1, 0, (1 << n) - 1, x, y, n % 2);
        cout << seg.t[1] << endl;
    }
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