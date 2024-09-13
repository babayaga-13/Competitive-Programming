#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        v[i] = {b[i], a[i]};
    }
    sort(v.begin(), v.end());
    if (v[0].first >= p)
    {
        cout << 1LL * n * p << endl;
        return;
    }
    ll ans = p, c = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first < p)
        {
            ans += v[i].first * min(c, v[i].second);
            c -= v[i].second;
        }
        else
            break;
        if (c < 1)
            break;
    }
    ans += max(c, 0LL) * p;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
