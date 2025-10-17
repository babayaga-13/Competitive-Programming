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
struct SegmentTree
{
    int n;
    vector<int> t;

    SegmentTree(int size)
    {
        n = size;
        t.assign(4 * n, 0);
    }

    int combine(int a, int b)
    {
        return a + b;
    }

    void update(int idx, int b, int e, int pos, int val)
    {
        if (b == e)
        {
            t[idx] = val;
            return;
        }
        int mid = (b + e) / 2;
        if (pos <= mid)
            update(idx * 2, b, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, e, pos, val);
        t[idx] = combine(t[idx * 2], t[idx * 2 + 1]);
    }

    int query(int idx, int b, int e, int l, int r)
    {
        if (l > e || r < b)
            return 0;
        if (l <= b && e <= r)
            return t[idx];
        int mid = (b + e) / 2;
        return combine(query(idx * 2, b, mid, l, r), query(idx * 2 + 1, mid + 1, e, l, r));
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pi> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    SegmentTree seg(n);
    int q;
    cin >> q;
    vi a(q);
    for (int i = 0; i < q; i++)
        cin >> a[i];
    int l = 1, r = q, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        bool f = false;
        for (int i = 0; i < mid; i++)
        {
            seg.update(1, 0, n - 1, a[i] - 1, 1);
        }
        for (int i = 0; i < m; i++)
        {
            int s = seg.query(1, 0, n - 1, v[i].first - 1, v[i].second - 1);
            if (s * 2 > (v[i].second - v[i].first + 1))
            {
                f = true;
                break;
            }
        }
        for (int i = 0; i < mid; i++)
        {
            seg.update(1, 0, n - 1, a[i] - 1, 0);
        }
        if (f)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
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