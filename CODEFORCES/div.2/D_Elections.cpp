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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<ll> b = a;
        b[0] += m;
        ll y = max_element(b.begin(), b.end()) - b.begin();
        ll x = *max_element(a.begin(), a.end());
        ll s = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i == y)
            {
                cout << "0 ";
                s += a[i];
            }
            else
            {
                if (a[i] + s + m >= x)
                {
                    cout << i << " ";
                }
                else
                {
                    cout << i + 1 << " ";
                }
                s += a[i];
            }
        }
        cout << endl;
    }

    return 0;
}
