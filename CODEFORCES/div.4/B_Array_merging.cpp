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
        ll a[n];
        set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        ll b[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            s.insert(b[i]);
        }
        map<ll, ll> m1, m2;
        ll c = 1;
        for (ll i = 0; i < n - 1; i++)
        {
            if (a[i] != a[i + 1])
            {
                m1[a[i]] = max(m1[a[i]], c);
                c = 1;
            }
            else
                c++;
        }
        m1[a[n - 1]] = max(m1[a[n - 1]], c);
        c = 1;
        for (ll i = 0; i < n - 1; i++)
        {
            if (b[i] != b[i + 1])
            {
                m2[b[i]] = max(m2[b[i]], c);
                c = 1;
            }
            else
                c++;
        }
        m2[b[n - 1]] = max(m2[b[n - 1]], c);
        ll ans = 0;
        for (auto u : s)
        {
            // cout << m1[u] << " " << m2[u] << endl;
            ans = max(ans, m1[u] + m2[u]);
        }
        cout << ans << endl;
    }
    return 0;
}
