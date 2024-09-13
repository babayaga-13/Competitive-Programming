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
        int n, m;
        cin >> n >> m;
        int ans = 0, c = 0, mn = INT_MAX;
        bool f = false;
        for (int i = 0; i < n * m; i++)
        {
            int x;
            cin >> x;
            ans += abs(x);
            mn = min(mn, abs(x));
            if (x < 0)
                c++;
            if (x == 0)
                f = true;
        }
        if (f || c % 2 == 0)
            cout << ans << endl;
        else
            cout << ans - mn * 2 << endl;
    }
    return 0;
}
