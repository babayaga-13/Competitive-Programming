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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> a, b;
    for (auto [u, v] : mp)
    {
        if (v > 1)
        {
            for (int i = 0; i < v / 2; i++)
                b.push_back(u);
        }
        if (v % 2 != 0)
            a.push_back(u);
    }

    if (b.empty())
    {
        cout << "-1\n";
        return;
    }
    if (b.size() > 1)
    {
        cout << b[0] << " " << b[0] << " " << b[1] << " " << b[1] << endl;
        return;
    }
    sort(all(a));
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i + 1] - a[i] < 2 * b[0])
        {
            cout << b[0] << " " << b[0] << " " << a[i] << " " << a[i + 1] << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}