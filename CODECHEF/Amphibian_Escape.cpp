#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
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
        ll n, k, h;
        cin >> n >> k >> h;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i >= h)
                ans += n;
            else
            {
                ll m = (k * i - h) / (k - 1);
                if (m > 0)
                    ans += min(n, m);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
