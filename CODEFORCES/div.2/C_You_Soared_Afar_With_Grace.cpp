#include <bits/stdc++.h>
#define ll long long
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
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

void solve()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    int p = 0;
    bool f = false;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (a[i] == b[i])
        {
            if (p)
                f = true;
            else
                p = i;
        }
        mp[{a[i], b[i]}] = i;
    }
    if (f || (n % 2 == 0 && p != 0) || (n % 2 && p == 0))
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!mp[{b[i], a[i]}])
        {
            cout << "-1\n";
            return;
        }
    }
    vector<pair<int, int>> ans;
    if (n % 2 && p != (n + 1) / 2)
    {
        ans.push_back({min(p, (n + 1) / 2), max(p, (n + 1) / 2)});
        swap(a[p], a[(n + 1) / 2]);
        swap(b[p], b[(n + 1) / 2]);
        mp[{a[p], b[p]}] = p;
        mp[{a[(n + 1) / 2], b[(n + 1) / 2]}] = (n + 1) / 2;
    }
    for (int i = 1; i <= n / 2; i++)
    {
        if (mp[{b[i], a[i]}] != (n - i + 1))
        {
            int x = mp[{b[i], a[i]}], y = (n - i + 1);
            ans.push_back({x, y});
            swap(a[x], a[y]);
            swap(b[x], b[y]);
            mp[{a[x], b[x]}] = x;
            mp[{a[y], b[y]}] = y;
        }
    }
    cout << ans.size() << endl;
    for (auto [u, v] : ans)
        cout << u << " " << v << endl;
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