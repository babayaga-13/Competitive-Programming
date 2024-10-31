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

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v, arr;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        arr.push_back({b, a});
    }
    sort(all(v));
    sort(all(arr));
    ll ans = 1, x = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= x)
        {
            ans++;
            x = v[i].second;
        }
    }

    ll ans1 = 1, y = arr[0].first;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].second >= y)
        {
            ans1++;
            y = arr[i].first;
        }
    }
    cout << max(ans, ans1) << endl;
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