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

const int MOD = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = ((__int128_t)ans * a) % MOD, n--;
        a = ((__int128_t)a * a) % MOD, n /= 2;
    }
    return ans;
}
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void solve()
{
    int n;
    cin >> n;
    int m = n;
    vector<int> v, ans;
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        v.push_back(n);
    for (auto u : v)
    {
        if (ans.size() == 0)
        {
            ans.push_back(u);
        }
        else if (ans.size() == 1)
        {
            ans.push_back(u);
        }
        else if (ans.size() == 2 && ans[0] == ans[1])
        {
            ans[1] *= u;
        }
        else if (ans.size() == 2 && ans[0] != ans[1])
        {
            ans.push_back(u);
        }
        else
            ans.back() *= u;
    }
    if (ans.size() == 3 && ans[0] != ans[1] && ans[0] != ans[2] && ans[1] != ans[2])
    {
        yes;
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
    else
        no;
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