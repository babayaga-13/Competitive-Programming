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
    int n, k;
    cin >> n >> k;
    int a[n + 1], b[n + 1], c[n + 1], x = 0, y = 0;
    int l = -1, r = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > k)
        {
            b[i] = 1;
            c[i] = 1;
        }
        else
        {
            b[i] = -1;
            c[i] = -1;
        }
    }
    for (int i = 2; i <= n; i++)
        b[i] += b[i - 1];
    for (int i = n - 1; i >= 1; i--)
        c[i] += c[i + 1];

    for (int i = 1; i <= n - 2; i++)
    {
        if (b[i] <= 0)
        {
            l = i;
            break;
        }
    }
    if (l == 1 && a[2] > k && n > 3)
    {
        l++;
    }
    if (l != -1)
    {
        for (int i = l + 1; i <= n - 1; i++)
        {
            if (b[i] - b[l] <= 0)
            {
                yes;
                return;
            }
        }
        for (int i = n; i > l + 1; i--)
        {
            if (c[i] <= 0)
            {
                yes;
                return;
            }
        }
    }
    for (int i = n; i > 2; i--)
    {
        if (c[i] <= 0)
        {
            r = i;
            break;
        }
    }
    if (r == n && a[n - 1] > k && n > 3)
        r--;

    if (r != -1)
    {
        for (int i = 1; i < r - 1; i++)
        {
            if (c[i] <= 0)
            {
                yes;
                return;
            }
        }
        for (int i = r - 1; i > 1; i--)
        {
            if (c[i] - c[r] <= 0)
            {
                yes;
                return;
            }
        }
    }
    no;
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