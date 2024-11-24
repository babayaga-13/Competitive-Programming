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
set<string> s1, s2, s3;
void solve()
{
    int m;
    cin >> m;
    string y;
    cin >> y;
    for (auto u : s1)
    {
        if (y.find(u) == string::npos)
        {
            cout << u << endl;
            return;
        }
    }
    for (auto u : s2)
    {
        if (y.find(u) == string::npos)
        {
            cout << u << endl;
            return;
        }
    }
    for (auto u : s3)
    {
        if (y.find(u) == string::npos)
        {
            cout << u << endl;
            return;
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
    int n = 26;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                string x = "";
                x += ('a' + i);
                s1.insert(x);
                x += ('a' + j);
                s2.insert(x);
                x += ('a' + k);
                s3.insert(x);
            }
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}