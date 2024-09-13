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
        ll x, y, ans = 0;
        cin >> x >> y;
        if (x == y)
        {
            cout << "0\n";
            continue;
        }
        if (x < y)
            swap(x, y);

        bool f = false;
        if (x % y || x % 2)
        {
            f = true;
        }
        else
        {
            x /= y;
            while (x > 1)
            {
                if (x % 8 == 0)
                    x /= 8;
                else if (x % 4 == 0)
                    x /= 4;
                else if (x % 2 == 0)
                    x /= 2;
                else
                {
                    f = true;
                    break;
                }
                ans++;
            }
        }
        if (f)
            cout << "-1\n";
        else
            cout << ans << endl;
    }
    return 0;
}
