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
    int a[n + 1], b[31][n + 1] = {0};
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < 31; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((a[j] & (1 << i)))
                b[i][j] = 1;
            else
                b[i][j] = 0;
            b[i][j] += b[i][j - 1];
        }
    }

    int t1;
    cin >> t1;
    while (t1--)
    {
        int k, l;
        cin >> l >> k;
        int p = l, q = n, ans = -1;
        while (p <= q)
        {
            int m = (p + q) / 2;
            int s = 0;
            for (int i = 0; i < 31; i++)
            {
                if (b[i][m] - b[i][l - 1] == (m - l + 1))
                {
                    s |= (1 << i);
                }
            }
            if (s >= k)
            {
                ans = m;
                p = m + 1;
            }
            else
                q = m - 1;
        }
        cout << ans << " ";
    }
    ln;
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