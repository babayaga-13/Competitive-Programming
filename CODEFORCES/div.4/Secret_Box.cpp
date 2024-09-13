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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll ans = 0;
        for (ll i = 1; i <= a; i++)
        {
            for (ll j = 1; j <= b; j++)
            {
                if ((d / (i * j)) <= c && d % (i * j) == 0)
                {
                    ll x = (a - i + 1) * (b - j + 1) * (c - (d / (i * j)) + 1);
                    ans = max(ans, x);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
