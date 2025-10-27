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
struct DSU
{
    vector<int> parent, sz;
    int comp;

    DSU(int n = 0)
    {
        init(n);
    }
    void init(int n)
    {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        comp = n;
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        comp--;
        return true;
    }
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    int get_size(int v)
    {
        return sz[find(v)];
    }

    int components_count() const
    {
        return comp;
    }
    void reset(int n)
    {
        init(n);
    }
    vector<vector<int>> get_all_components()
    {
        unordered_map<int, vector<int>> groups;
        for (int i = 1; i < (int)parent.size(); i++)
            groups[find(i)].push_back(i);
        vector<vector<int>> res;
        for (auto &x : groups)
            res.push_back(x.second);
        return res;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = power(n, k);
    vi cnt(n + 1, 1);
    cnt[0] = 0;
    DSU d(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0)
        {
            d.unite(x, y);
            cnt[x] = 0;
            cnt[y] = 0;
        }
    }
    ans -= accumulate(all(cnt), 0LL);
    vi c(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            int x = d.find(i);
            if (!c[x])
            {
                c[x] = 1;
                ans = (ans - power(d.get_size(x), k) + MOD) % MOD;
            }
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
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}