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
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' || s[i] == '8')
        {
            yes;
            cout << s[i];
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int x = (s[i] - '0'), y = s[j] - '0', z = s[k] - '0';
                int ans = -1;
                if ((x * 100 + y * 10 + z) % 8 == 0)
                    ans = x * 100 + y * 10 + z;
                else if ((x * 10 + y) % 8 == 0)
                    ans = x * 10 + y;
                else if ((x * 10 + y) % 8 == 0)
                    ans = x * 10 + y;
                else if ((x * 10 + z) % 8 == 0)
                    ans = x * 10 + z;
                else if ((y * 10 + z) % 8 == 0)
                    ans = y * 10 + z;

                if (ans > 0)
                {
                    yes;
                    cout << ans;
                    return;
                }
            }
        }
    }
    no;
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