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

const int N = 1000000007; // Standard value for modulo

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = ((__int128_t)ans * a) % N, n--;
        a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<int>> v(k + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v[x].push_back(i);
    }

    ll ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (v[i].empty())
            continue;

        ll c1 = 0, c2 = 0;
        ll x = 1;
        for (int j = 0; j < v[i].size(); j++)
        {
            ll y = v[i][j] - x;
            if (y > c1)
                c2 = c1, c1 = y;
            else
                c2 = max(c2, y);
            x = v[i][j] + 1;
        }

        ll y = n + 1 - x;
        if (y > c1)
            c2 = c1, c1 = y;
        else
            c2 = max(c2, y);
        ans = min(ans, max((c1) / 2, c2));
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
