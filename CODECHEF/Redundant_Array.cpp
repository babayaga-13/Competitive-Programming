#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll x;
        set<ll> s;
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s.insert(x);
            mp[x]++;
        }
        ll ans = INT_MAX;
        for (auto u : s)
        {
            ll sum = (n - mp[u]) * u;
            ans = min(ans, sum);
        }
        ans = min(ans, (n - mp[1]));
        cout << ans << endl;
    }
    return 0;
}
