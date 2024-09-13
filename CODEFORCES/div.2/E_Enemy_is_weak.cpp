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
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        pbds<ll> p, p2;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            p2.insert(arr[i]);
        }
        p.insert(arr[0]);

        if (n == 1)
        {
            cout << 0 << endl;
            break;
        }

        ll ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            ll x = arr[i];
            ll cnt = p.order_of_key(x);
            ll fir = p2.order_of_key(x);
            ll aft = fir - cnt;
            ll bef = p.size() - cnt;
            ans += aft * bef;
            p.insert({x});
        }

        cout << ans << endl;
    }
    return 0;
}
