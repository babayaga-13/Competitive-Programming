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
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int x = v[0];
        int ans = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] - x - w > d || c >= k)
            {
                ans++;
                x = v[i];
                c = 1;
            }
            else
                c++;
        }
        if (c > 0)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
