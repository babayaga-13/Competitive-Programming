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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll x = 0;
    for (int i = 0; i < k - 1; i++)
    {
        if (a[i] > a[k - 1])
        {
            x = i;
            break;
        }
    }
    ll ans = 0;
    swap(a[0], a[k - 1]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[0])
            ans++;
        else
            break;
    }
    swap(a[0], a[k - 1]);
    swap(a[x], a[k - 1]);
    ll ans1 = 0;
    if (x != 0)
        ans1++;
    for (int i = x + 1; i < n; i++)
    {
        if (a[i] < a[x])
            ans1++;
        else
            break;
    }

    cout << max(ans, ans1) << endl;
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