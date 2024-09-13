#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define count_one(x) __builtin_popcount(x)
#define trailing_zero(x) __builtin_ctz(x)
#define leading_zero(x) __builtin_clz(x)
#define gcd __gcd
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = (ans * a) % N, n--;
        else
            a = (a * a) % N, n /= 2;
    }
    return ans;
}

vector<vector<int>> cycles;
vector<int> c;

void dfs(int u, int p[], int vis[])
{
    vector<int> vec;
    int cur = u;
    while (vis[cur] == 0)
    {
        vis[cur] = 1;
        vec.push_back(cur);
        cur = p[cur];
    }

    if (vis[cur] == 1)
    {
        vector<int> cycle;
        int start = find(vec.begin(), vec.end(), cur) - vec.begin();
        for (int i = start; i < vec.size(); ++i)
        {
            cycle.push_back(vec[i]);
            c[vec[i]] = cycles.size();
        }
        cycles.push_back(cycle);
    }

    for (int v : vec)
    {
        vis[v] = 2;
    }
}

void solve()
{
    int n;
    cin >> n;

    int v[n], vis[n] = {0}, ans[n];
    bool x[n];

    c.assign(n, -1);

    for (int i = 0; i < n; ++i)
    {
        int y;
        cin >> y;
        v[i] = y - 1;
    }

    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            x[i] = 1;
        else
            x[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        if (vis[i] == 0)
        {
            dfs(i, v, vis);
        }
    }

    vector<int> a(cycles.size(), 0);
    for (int i = 0; i < n; ++i)
    {
        if (c[i] != -1)
        {
            a[c[i]] += x[i];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        ans[i] = a[c[i]];
    }

    for (int u : ans)
    {
        cout << u << " ";
    }
    cout << endl;
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