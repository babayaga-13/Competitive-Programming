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
    // cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n + 1), a(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            cin >> v[i];
        while (m--)
        {
            ll x, y;
            cin >> x >> y;
            a[x]++;
            if (y < n)
                a[y + 1]--;
        }
        for (ll i = 1; i <= n; i++)
            a[i] += a[i - 1];
        sort(v.begin(), v.end());
        sort(a.begin(), a.end());
        ll sum = 0;
        for (ll i = 1; i <= n; i++)
            sum += (a[i] * v[i]);
        cout << sum << endl;
    }
    return 0;
}
