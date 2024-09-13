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

const int MOD = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = (ans * a) % MOD, n--;
        else
            a = (a * a) % MOD, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v + n);

    ll l = 0, r = 0, ans = 0, s = 0;
    while (r < n)
    {
        s += v[r];
        while (s > k || (v[r] - v[l] > 1))
        {
            s -= v[l];
            l++;
        }
        ans = max(ans, s);
        r++;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
