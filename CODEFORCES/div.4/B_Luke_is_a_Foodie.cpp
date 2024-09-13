#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = a[0], r = a[0];
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > r)
                r = a[i];
            else if (a[i] < l)
                l = a[i];
            if (r - l > 2 * k)
            {
                l = a[i], r = a[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
