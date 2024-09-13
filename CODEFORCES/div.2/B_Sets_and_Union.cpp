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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<set<ll>> v(n);
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll m;
            cin >> m;
            for (ll j = 0; j < m; j++)
            {
                ll x;
                cin >> x;
                mp[x]++;
                v[i].insert(x);
            }
        }
        ll ans = 0;
        for (ll i = 1; i <= 50; i++)
        {
            if (mp[i] == 0)
                continue;
            set<ll> s;
            for (ll j = 0; j < n; j++)
            {
                if (v[j].find(i) == v[j].end())
                {
                    for (auto u : v[j])
                        s.insert(u);
                }
            }
            ans = max(ans, (ll)s.size());
        }
        cout << ans << endl;
    }
    return 0;
}
