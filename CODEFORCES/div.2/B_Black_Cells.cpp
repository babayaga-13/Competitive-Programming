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

const int N = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = ((__int128_t)ans * a) % N, n--;
        else
            a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n % 2 == 0)
    {
        ll ans = 1;
        for (int i = 2; i <= n; i += 2)
            ans = max(ans, a[i] - a[i - 1]);
        cout << ans << endl;
    }
    else if (n == 1)
    {
        cout << "1\n";
    }
    else
    {
        ll ans = 1e18;
        for (int i = 1; i <= n; i += 2)
        {
            ll x = 0;
            for (int j = 1; j < i; j += 2)
                x = max(x, a[j + 1] - a[j]);
            for (int j = i + 2; j <= n; j += 2)
                x = max(x, a[j] - a[j - 1]);

            ans = min(ans, x);
        }
        cout << ans << endl;
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