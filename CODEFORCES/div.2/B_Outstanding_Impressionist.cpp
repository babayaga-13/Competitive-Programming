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
    int n;
    cin >> n;
    int m = 2 * n + 3;

    vector<int> pref(m, 0), l(n), r(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        if (l[i] == r[i])
        {
            pref[l[i]] = 1;
            mp[l[i]]++;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        pref[i] += pref[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (l[i] == r[i])
        {
            if (mp[l[i]] == 1)
                cout << "1";
            else
                cout << "0";
        }
        else
        {
            if (pref[r[i]] - pref[l[i] - 1] < r[i] - l[i] + 1)
                cout << "1";
            else
                cout << "0";
        }
    }
    cout << endl;
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