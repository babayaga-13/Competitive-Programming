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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll c[26] = {0};
    for (int i = 0; i < n; i++)
    {
        c[s[i] - 'a']++;
    }
    ll a = -1, b = -1;
    ll mx = 0, mn = n;

    for (int i = 0; i < 26; i++)
    {
        if (c[i] > mx)
        {
            mx = c[i];
            a = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (c[i] > 0 && c[i] < mn && a != i)
        {
            mn = c[i];
            b = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ('a' + b))
        {
            s[i] = ('a' + a);
            break;
        }
    }
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