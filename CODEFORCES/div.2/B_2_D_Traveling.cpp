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

void solve()
{
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    a--;
    b--;
    ll v[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    if (a + 1 <= k && b + 1 <= k)
    {
        cout << "0\n";
        return;
    }
    ll ans1 = LLONG_MAX / 2, ans2 = LLONG_MAX / 2;
    for (int i = 0; i < k; i++)
    {
        ans1 = min(ans1, (abs(v[i][0] - v[a][0]) + abs(v[i][1] - v[a][1])));
        ans2 = min(ans2, (abs(v[i][0] - v[b][0]) + abs(v[i][1] - v[b][1])));
    }
    ll ans = ans1 + ans2;
    ans = min(ans, (abs(v[a][0] - v[b][0]) + abs(v[a][1] - v[b][1])));
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