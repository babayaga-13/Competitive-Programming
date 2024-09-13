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
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll l = 1, h = min((ll)2e9, 2 * n), a = 0;
        while (l <= h)
        {
            long long m = (l + h) / 2;
            if ((m * (m - 1) / 2) <= n)
            {
                a = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }
        ll ans = n - (a * (a - 1)) / 2;
        cout << ans + a << endl;
    }
    return 0;
}
