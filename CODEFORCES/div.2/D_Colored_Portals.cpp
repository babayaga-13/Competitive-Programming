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
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
const int N = 1e8;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    map<char, int> index;
    index['R'] = 0, index['G'] = 1, index['B'] = 2, index['Y'] = 3;
    for (int i = 1; i <= n; i++)
    {
        int mask = 0;
        string str;
        cin >> str;
        mask |= (1 << index[str[0]]);
        mask |= (1 << index[str[1]]);
        a[i] = mask;
    }
    vector<int> ldp(n + 1, -1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        for (auto &[mask, ind] : mp)
        {
            if (count_one(mask & a[i]) == 1)
                ldp[i] = max(ldp[i], ind);
        }
        mp[a[i]] = i;
    }
    vector<int> rdp(n + 1, N);
    mp.clear();
    for (int i = n; i >= 1; i--)
    {
        for (auto &[mask, ind] : mp)
        {
            if (count_one(mask & a[i]) == 1)
                rdp[i] = min(rdp[i], ind);
        }
        mp[a[i]] = i;
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        int ans = y - x;
        if ((a[x] & a[y]) == 0)
        {
            int curr = N;
            if (ldp[x] != -1)
                curr = min(curr, 2 * (x - ldp[x]));
            if (rdp[x] != N)
                curr = min(curr, 2 * (max(0, rdp[x] - y)));
            ans += curr;
        }
        if (ans >= N)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
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