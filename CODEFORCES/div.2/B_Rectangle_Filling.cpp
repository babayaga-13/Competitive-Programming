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
            ans = ((__int128_t)ans * a) % N, n--;
        else
            a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    string a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if ((a[0][0] == a[n - 1][m - 1]) || (a[n - 1][0] == a[0][m - 1]))
    {
        yes;
        return;
    }

    bool f = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i][0] != a[i + 1][0] || a[i][m - 1] != a[i + 1][m - 1])
            f = false;
    }

    if (f)
    {
        no;
        return;
    }

    f = true;
    for (int j = 0; j < m - 1; j++)
    {
        if (a[0][j] != a[0][j + 1] || a[n - 1][j] != a[n - 1][j + 1])
            f = false;
    }

    if (f)
    {
        no;
        return;
    }
    yes;
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