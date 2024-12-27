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
    cout << "1 " << n << " ";
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            x = i;
            break;
        }
    }
    if (x == 0)
    {
        cout << "1 1\n";
        return;
    }
    else
    {
        ll m = n - x, l = 1, r = m, j;
        string s2 = s.substr(x, m);
        string v2(m, 0);

        for (j = 0; j < x; j++)
        {
            if (s[j] == '0')
                continue;
            string v1(m, 0);
            for (int i = 0; i < m; i++)
            {
                v1[i] = (s[j + i] != s2[i]);
            }
            if (v1 > v2)
            {
                v2 = v1;
                l = j + 1;
                r = j + m;
            }
        }

        cout << l << ' ' << r << '\n';
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