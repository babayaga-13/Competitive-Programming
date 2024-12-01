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
    int q;
    cin >> q;
    string y = "1100";
    int count = 0;
    int pos = 0;
    while ((pos = s.find(y, pos)) != string::npos)
    {
        count++;
        pos += y.length();
    }
    while (q--)
    {
        int x;
        char c;
        cin >> x >> c;
        x--;
        if (s[x] == c)
        {
            if (count > 0)
                yes;
            else
                no;
        }
        else
        {
            if (x >= 0 && x + 3 < n && s[x] == '1' && s[x + 1] == '1' && s[x + 2] == '0' && s[x + 3] == '0')
                count--;
            else if (x >= 1 && x + 2 < n && s[x - 1] == '1' && s[x] == '1' && s[x + 1] == '0' && s[x + 2] == '0')
                count--;
            else if (x >= 2 && x + 1 < n && s[x - 2] == '1' && s[x - 1] == '1' && s[x] == '0' && s[x + 1] == '0')
                count--;
            else if (x >= 3 && x < n && s[x - 3] == '1' && s[x - 2] == '1' && s[x - 1] == '0' && s[x] == '0')
                count--;
            s[x] = c;
            if (x >= 0 && x + 3 < n && s[x] == '1' && s[x + 1] == '1' && s[x + 2] == '0' && s[x + 3] == '0')
                count++;
            else if (x >= 1 && x + 2 < n && s[x - 1] == '1' && s[x] == '1' && s[x + 1] == '0' && s[x + 2] == '0')
                count++;
            else if (x >= 2 && x + 1 < n && s[x - 2] == '1' && s[x - 1] == '1' && s[x] == '0' && s[x + 1] == '0')
                count++;
            else if (x >= 3 && x < n && s[x - 3] == '1' && s[x - 2] == '1' && s[x - 1] == '0' && s[x] == '0')
                count++;
            if (count > 0)
                yes;
            else
                no;
        }
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