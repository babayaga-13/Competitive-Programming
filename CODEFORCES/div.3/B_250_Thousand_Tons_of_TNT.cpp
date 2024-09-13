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
        ll b, n, ans = 0;
        cin >> n;
        vector<ll> a(n + 1, 0);

        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }

        for (ll i = 1; i <= n; ++i)
        {
            vector<ll> v;
            if (n % i == 0)
            {
                for (ll j = i; j <= n; j += i)
                {
                    v.push_back(a[j] - a[j - i]);
                }
                sort(v.begin(), v.end());
                ans = max(ans, v[(ll)v.size() - 1] - v[0]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
