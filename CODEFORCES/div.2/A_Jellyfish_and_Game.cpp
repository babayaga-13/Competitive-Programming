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
    int x, y, n;
    long long s = 0;
    cin >> x >> y >> n;
    int a[x], b[y];
    for (int i = 0; i < x; i++)
        cin >> a[i];
    for (int i = 0; i < y; i++)
        cin >> b[i];
    sort(a, a + x);
    sort(b, b + y);
    if (n >= 1)
    {
        if (a[0] < b[y - 1])
            swap(a[0], b[y - 1]);
    }
    sort(a, a + x);
    sort(b, b + y);
    if (n >= 2)
        swap(b[0], a[x - 1]);
    if (n % 2 != 0 && n > 2)
        swap(b[0], a[x - 1]);
    for (int i = 0; i < x; i++)
        s += a[i];
    cout << s << endl;
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