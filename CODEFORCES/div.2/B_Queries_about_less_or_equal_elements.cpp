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
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        pbds<int> p;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            p.insert(x);
        }
        while (q--)
        {
            int y;
            cin >> y;
            int ans = p.order_of_key(y + 1);
            cout << ans << " ";
        }
    }
    return 0;
}
