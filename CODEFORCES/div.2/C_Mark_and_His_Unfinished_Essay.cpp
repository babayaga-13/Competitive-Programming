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
    ll n, c, q;
    string s;
    cin >> n >> c >> q >> s;
    vector<ll> index;
    vector<pair<ll, ll>> segment;
    segment.push_back({0, n - 1});
    index.push_back(0);
    index.push_back(n);
    ll l, r;
    for (int i = 0; i < c; i++)
    {

        cin >> l >> r;
        l--, r--;
        segment.push_back({l, r});
        index.push_back(index.back() + (r - l + 1));
    }

    while (q--)
    {
        ll x;
        cin >> x;
        x--;
        ll ans;
        for (int i = c; i >= 0; i--)
        {
            if (x < index[i + 1] && x >= index[i])
            {
                x = x - index[i];
                x += segment[i].first;
            }
        }
        cout << s[x] << endl;
    }
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