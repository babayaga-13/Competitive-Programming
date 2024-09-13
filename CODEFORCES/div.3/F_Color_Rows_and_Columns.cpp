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
    int n, k;
    cin >> n >> k;
    const int inf = int(1e9);
    vector<int> dp(k + 1, inf);
    dp[0] = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        vector<int> me(k + 1, inf);
        me[0] = 0;
        int cnt = 0;
        int cost = 0;
        while (cnt < k && (a > 0 || b > 0))
        {
            if (a < b)
            {
                swap(a, b);
            }
            cnt += 1;
            cost += b;
            a -= 1;
            me[cnt] = cost;
        }
        for (int i = k - 1; i >= 0; i--)
        {
            for (int j = 1; j <= k - i; j++)
            {
                dp[i + j] = min(dp[i + j], dp[i] + me[j]);
            }
        }
    }
    cout << (dp[k] == inf ? -1 : dp[k]) << '\n';
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