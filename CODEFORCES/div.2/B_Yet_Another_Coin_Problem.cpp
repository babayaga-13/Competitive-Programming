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

const int N = 2e5 + 7;
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
int dp[N];
ll c[5] = {1, 3, 6, 10, 15};
void solve()
{
    ll n;
    cin >> n;
    if (n <= N)
    {
        cout << dp[n] << endl;
    }
    else
    {
        int ans = (n - N) / 15;
        n -= 15 * ans;
        while (n >= N)
        {
            n -= 15;
            ans++;
        }
        cout << dp[n] + ans << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    dp[0] = 0;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1e9;
        for (auto u : c)
        {
            if (i - u >= 0)
            {
                dp[i] = min(dp[i], dp[i - u] + 1);
            }
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}