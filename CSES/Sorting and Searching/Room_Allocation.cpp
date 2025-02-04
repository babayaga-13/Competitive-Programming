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
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y, i});
    }

    sort(all(v));

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({v[0][1], 1});

    int c = 1;
    vector<int> ans(n);
    ans[v[0][2]] = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i][0] > p.top().first)
        {
            int x = p.top().second;
            p.pop();
            ans[v[i][2]] = x;
            p.push({v[i][1], x});
        }
        else
        {
            c++;
            ans[v[i][2]] = c;
            p.push({v[i][1], c});
        }
    }

    cout << c << endl;
    for (auto u : ans)
        cout << u << " ";
    cout << endl;
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
