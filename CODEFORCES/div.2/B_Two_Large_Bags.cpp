#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
    vector<int> v(n), b;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {

        cin >> v[i];
        mp[v[i]]++;
    }
    sort(all(v));
    int m = v[n - 1];
    for (int i = v[0]; i <= m; i++)
    {
        if (mp[i] == 1)
        {
            no;
            return;
        }

        if (mp[i] == 0)
            continue;
        int x = mp[i] - 2;
        if (mp[i + 1])
            mp[i + 1] += x;
        else
            mp[i + 1] = x;
        mp[i] -= x;
    }
    for (auto u : mp)
    {
        if (u.second % 2)
        {
            no;
            return;
        }
    }
    yes;
}

signed main()
{

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}