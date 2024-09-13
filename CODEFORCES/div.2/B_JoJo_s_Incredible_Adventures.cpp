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
    string s;
    cin >> s;
    ll n = s.size();
    s += s;
    ll c = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            c++;
        else
        {
            ans = max(ans, c);
            c = 0;
        }
    }
    if (c == s.size())
        c /= 2;
    ans = max(ans, c);
    if (ans == n || ans == 0)
        cout << ans * ans << endl;
    else
    {
        if (ans % 2)
        {
            ans++;
            cout << ans * ans / 4 << endl;
        }
        else
            cout << (ans / 2) * (ans / 2 + 1) << endl;
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