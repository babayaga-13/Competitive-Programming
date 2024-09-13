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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        ll lc = a[0];
        for (int i = 1; i < n; i++)
            lc = (((a[i] * lc)) / (__gcd(a[i], lc)));
        ll sum = 0;
        vector<ll> ans(n);
        for (ll i = 0; i < n; i++)
        {
            sum += lc / a[i];
            ans[i] = (lc / a[i]);
        }
        if (sum < lc)
        {
            for (ll i = 0; i < n; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
