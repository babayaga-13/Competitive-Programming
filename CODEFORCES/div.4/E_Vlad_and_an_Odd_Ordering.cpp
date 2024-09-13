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
        ll n, k;
        cin >> n >> k;
        ll c = 0;
        for (int i = 1;; i *= 2)
        {
            ll x = n / i;
            ll y = (x + 1) / 2;
            if (k <= y)
            {
                ll ans = 2 * k - 1;
                cout << ans * i << endl;
                break;
            }
            else
                k -= y;
        }
    }
}
