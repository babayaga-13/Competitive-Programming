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
struct Node
{
    int ones;
    int zeros;
    int best;

    Node(int o = 0, int z = 0, int b = 1e9)
    {
        ones = o;
        zeros = z;
        best = b;
    }
};
struct SegTree
{
    vector<Node> seg;
    vector<int> lazy;
    int n;

    SegTree(int sz)
    {
        n = sz;
        seg.assign(4 * n + 5, Node());
        lazy.assign(4 * n + 5, -1);
    }

    Node merge(Node a, Node b)
    {
        Node res;

        res.ones = a.ones + b.ones;
        res.zeros = a.zeros + b.zeros;

        res.best = min(a.best,
                       a.zeros + b.best);

        return res;
    }

    void apply(int node, int l, int r, int val)
    {
        int len = r - l + 1;

        if (val == 0)
        {
            seg[node] = Node(0, len, 1e9);
        }
        else
        {
            seg[node] = Node(len, 0, 0);
        }

        lazy[node] = val;
    }

    void push(int node, int l, int r)
    {
        if (lazy[node] == -1 || l == r)
            return;

        int mid = (l + r) >> 1;

        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = -1;
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            // initially all zero
            seg[node] = Node(0, 1, 1e9);
            return;
        }

        int mid = (l + r) >> 1;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2],
                          seg[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int L, int R, int val)
    {
        if (r < L || l > R)
            return;

        if (L <= l && r <= R)
        {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) >> 1;

        update(node * 2, l, mid, L, R, val);
        update(node * 2 + 1, mid + 1, r, L, R, val);

        seg[node] = merge(seg[node * 2],
                          seg[node * 2 + 1]);
    }

    Node query()
    {
        return seg[1];
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    SegTree st(n);

    st.build(1, 1, n);

    while (q--)
    {
        int type, L, R;
        cin >> type;

        if (type == 0)
        {
            cin >> L >> R;
            st.update(1, 1, n, L, R, 0);
        }
        else if (type == 1)
        {
            cin >> L >> R;
            st.update(1, 1, n, L, R, 1);
        }
        else
        {
            Node root = st.query();

            int ones = root.ones;
            int zeros = n - ones;

            st.update(1, 1, n, 1, zeros, 0);
            st.update(1, 1, n, zeros + 1, n, 1);
        }

        Node root = st.query();

        int ans;

        if (root.ones == 0)
            ans = 1;
        else
            ans = root.zeros - root.best + 1;

        cout << ans << '\n';
    }
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