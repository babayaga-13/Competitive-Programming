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
    // cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = 0, c = n;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = n - 1; i >= 0; i--)
        {
            ll x = a[i];
            ll y = (k + x - 1) / x;

            if (y <= c && y * x > k)
            {
                c -= y;
                ans++;
            }
            else if (y < c && y * x == k)
            {
                y++;
                c -= y;
                ans++;
            }
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
