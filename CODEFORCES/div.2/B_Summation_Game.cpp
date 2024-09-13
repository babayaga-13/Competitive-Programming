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
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        sort(v.rbegin(), v.rend() - 1);
        for (int i = 1; i <= n; i++)
            v[i] += v[i - 1];
        ll ans = INT_MIN;
        for (int i = 0; i <= k; i++)
        {
            ll cur = v[n] - 2 * v[min(x + i, n)] + v[i];
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
