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
        a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;

    for (int i = 0; i < min(n, m) / 2; i++)
    {
        string s = "";
        for (int j = i; j < m - i; j++)
            s += a[i][j];
        for (int k = i + 1; k < n - i; k++)
            s += a[k][m - i - 1];
        for (int j = m - i - 2; j >= i; j--)
            s += a[n - i - 1][j];
        for (int k = n - i - 2; k > i; k--)
            s += a[k][i];
        s += s[0];
        s += s[1];
        s += s[2];
        // cout << s << endl;
        string y = "1543";

        int pos = 0;
        while ((pos = s.find(y, pos)) != string::npos)
        {
            ans++;
            pos += y.length();
        }
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