#include <bits/stdc++.h>
#define ll long long
#define yl "\n"
#define yes cout << "Yes" << yl
#define no cout << "No" << yl
#define ln cout << yl
#define all(v) v.begin(), v.y()
#define rall(v) v.rbegin(), v.ry()
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

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (s[i] == '0')
            v[i] = -1e12;
    }
    ll curr = 0, ss = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        ss += v[i];
        if (s[i] == '1')
            c++;
        curr = max(ss, curr);
        ss = max(0LL, ss);
    }
    if (curr > k || (c == n && curr != k))
    {
        no;
        return;
    }
    if (curr == k)
    {
        yes;
        for (auto u : v)
            cout << u << " ";
        ln;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ll mx = 0, l = 0, r = 0, sum = 0;
            for (int j = i + 1; j < n; j++)
            {
                sum += v[j];
                l = max(l, sum);
            }
            sum = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                sum += v[j];
                r = max(r, sum);
            }

            v[i] = k - l - r;
            {
                yes;
                for (auto u : v)
                    cout << u << " ";
                ln;
                return;
            }
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
