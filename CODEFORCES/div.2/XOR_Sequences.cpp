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
        int x, y;
        cin >> x >> y;
        int a = x ^ y;

        if (a == 0)
        {
            cout << 1 << endl;
            continue;
        }

        int ans = 0;
        while ((a & 1) == 0)
        {
            a >>= 1;
            ans++;
        }

        cout << (1 << ans) << endl;
    }

    return 0;
}
