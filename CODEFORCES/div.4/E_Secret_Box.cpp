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
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        ll ans = 0;
        for (ll i = 1; i <= x; i++)
        {
            for (ll j = 1; j <= y; j++)
            {
                if ((k / (i * j)) <= z && (k % (i * j) == 0))
                {
                    ll a = (x - i + 1) * (y - j + 1) * (z - (k / (i * j)) + 1);
                    ans = max(ans, a);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
