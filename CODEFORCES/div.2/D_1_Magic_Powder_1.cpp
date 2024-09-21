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
int n, k;
vector<int> a(1001), b(1001);
bool check(int m)
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] / a[i] >= m)
            continue;
        else
        {
            int y = a[i] * m;
            x += (y - b[i]);
        }
        if (x > k)
            return false;
    }
    return true;
}
void solve()
{

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int l = 0, h = 1e6 + 1, ans = 0;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}