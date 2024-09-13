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
        ll n, x;
        cin >> n >> x;
        ll ans = 0;
        for (int i = 1; i <= min(n, x); i++)
        {
            for (int j = 1; i * j <= n; j++)
            {
                ll y = (n - i * j) / (i + j);
                if (i + j <= x)
                {
                    ans += min(y, x - i - j);
                }
                else
                    break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
