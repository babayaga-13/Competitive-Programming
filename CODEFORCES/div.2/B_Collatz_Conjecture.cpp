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

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;

        while (x != 1)
        {
            ll a = y - x % y;
            if (k < a)
            {
                cout << x + k << endl;
                goto next;
            }
            x += a;
            k -= a;
            while (x % y == 0)
            {
                x /= y;
            }
        }
        cout << 1 + k % (y - 1) << endl;

    next:
        continue;
    }

    return 0;
}
