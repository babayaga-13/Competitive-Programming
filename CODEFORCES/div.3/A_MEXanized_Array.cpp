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
        int n, k, x;
        cin >> n >> k >> x;
        if (k > n || (k - x) > 1)
        {
            cout << "-1\n";
            continue;
        }
        ll ans = 0;
        ans = ((k - 1) * (k)) / 2;
        n -= k;
        if (k == x)
            ans += (n * (x - 1));
        else
            ans += (n * x);
        cout << ans << endl;
    }
    return 0;
}
