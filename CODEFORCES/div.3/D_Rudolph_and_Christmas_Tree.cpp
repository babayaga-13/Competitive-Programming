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
    int n, d, h;
    cin >> n >> d >> h;
    long double a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long double ans = ((long double)d * h) / 2.0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] >= h)
            ans += ((long double)d * h) / 2.0;
        else
        {
            long double h1 = (a[i + 1] - a[i]) * 1.0;
            long double k = (h - h1) / (h * 1.0);
            long double d1 = d * k * 1.0;
            ans += ((long double)(d + d1) * h1 / 2.0);
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
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