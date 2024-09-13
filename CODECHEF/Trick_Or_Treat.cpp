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
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        map<ll, ll> mp1, mp2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp1[a[i] % m]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mp2[b[i] % m]++;
        }
        ll ans = 0;
        for (auto u : mp1)
        {
            ans += (u.second * mp2[(m - u.first) % m]);
        }
        cout << ans << endl;
    }
    return 0;
}
