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
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int m1[n + 1], m2[n + 1];
    bool f[n + 1] = {0};
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = 1;
        while (f[x] == 1)
            x++;
        m1[i] = x;
    }
    bool f1[n + 1] = {0};
    x = 0;
    for (int i = n; i > 0; i--)
    {
        f1[a[i]] = 1;
        while (f1[x] == 1)
            x++;
        m2[i] = x;
    }
    for (int i = 1; i < n; i++)
    {
        if (m1[i] == m2[i + 1])
        {
            cout << "2\n";
            cout << "1 " << i << endl;
            cout << i + 1 << " " << n << endl;

            return;
        }
    }
    cout << "-1\n";
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