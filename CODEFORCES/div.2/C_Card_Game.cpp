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
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                s += a[i];
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
            {
                if (a[i] > 0)
                {
                    ans = max(ans, s);
                    s -= a[i];
                }
                else
                {
                    ans = max(ans, s + a[i]);
                }
            }
            else
            {
                if (a[i] > 0)
                {
                    s -= a[i];
                    ans = max(ans, s);
                }
                else
                {
                    ans = max(ans, s);
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
