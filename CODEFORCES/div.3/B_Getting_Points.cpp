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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll x = (n - 1) / 7 + 1;
    ll y = x / 2;
    x %= 2;
    ll c = 2 * t + l;
    if (y * c >= p)
    {
        cout << n - (p + c - 1) / c << endl;
        return;
    }
    else
    {
        n -= y;
        p -= (y * c);
        if (x)
        {
            n--;
            p -= (t + l);
            if (p <= 0)
            {
                cout << n << endl;
                return;
            }
        }

        n -= (p + l - 1) / l;
        cout << n << endl;
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