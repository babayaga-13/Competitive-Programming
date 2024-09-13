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
        ll n, c, d, s = 0;
        cin >> n >> c >> d;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < min(d, n); i++)
        {
            s += a[i];
        }
        if (a[0] * d < c)
        {
            cout << "Impossible\n";
            continue;
        }
        if (s >= c)
        {
            cout << "Infinity\n";
            continue;
        }
        ll ans = 0;
        int l = 1, h = d;
        while (l <= h)
        {
            int m = (l + h) / 2;
            ll sum = 0;
            for (int i = 0; i < d; i++)
            {
                if (i % m < n)
                {
                    sum += a[i % m];
                }
            }
            if (sum >= c)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
