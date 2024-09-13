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
        vector<ll> a(n), b(n + 1);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i <= n; i++)
            cin >> b[i];
        ll ans = 0, y = INT_MAX;
        bool f = false;
        ll x = b[n];
        for (ll i = 0; i < n; i++)
        {
            ans += abs(a[i] - b[i]);
            if (x >= min(a[i], b[i]) && x <= max(a[i], b[i]))
                f = true;
            else
            {
                ll z = min(abs(x - a[i]), abs(x - b[i]));
                y = min(y, z);
            }
        }
        if (f)
            ans++;
        else
            ans += (1 + y);
        cout << ans << endl;
    }
    return 0;
}
