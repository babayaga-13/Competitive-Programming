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
    ll a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    vector<ll> v;
    for (int i = 0; i < m - 1; i++)
        v.push_back(a[i + 1] - a[i] - 1);

    v.push_back((a[0] - 1) + n - a[m - 1]);
    sort(rall(v));

    ll ans = 0, c = 0;
    for (int i = 0; i < m; i++)
    {
        if (v[i] - c == 1 || v[i] - c == 2)
            ans++, c += 2;
        else if (v[i] - c > 2)
            ans += (v[i] - 1 - c), c += 4;
        else
            break;
    }
    cout << n - ans << endl;
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