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
            ans = (ans * a) % N, n--;
        else
            a = (a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, k, s = 0;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i] % N;
    }
    s = (s % N + N) % N;
    ll x = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        c += a[i] % N;
        c = max(c, 0LL);
        x = max(x, c);
    }
    x %= N;
    ll ans = (s + (power(2, k) - 1) * x % N + N) % N;
    cout << (ans % N + N) % N << endl;
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
