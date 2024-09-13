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

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    if (a.first.first == b.first.first)
        return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first.first >> v[i].first.second, v[i].second = i + 1;
    sort(v.begin(), v.end(), cmp);

    int x = v[0].first.second;
    int y = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if (v[i].first.second <= x)
        {
            cout << v[i].second << " " << y << endl;
            return;
        }
        if (v[i].first.second > x)
        {
            x = v[i].first.second;
            y = v[i].second;
        }
    }

    cout << "-1 -1\n";
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