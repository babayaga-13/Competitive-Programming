#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define gcd __gcd
using namespace std;

const int MOD = 1e9 + 7;
const int N = 200000 + 5;

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

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1, 0), buc(n + 1, INT_MAX), dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = min(dp[i - 1] + 1, buc[a[i]]);
        buc[a[i]] = min(buc[a[i]], dp[i - 1]);
    }

    cout << n - dp[n] << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
