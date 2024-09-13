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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        map<ll, ll> mp;
        ll sum = 0, c = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += (s[i] == '0') ? 1 : -1;
            c += mp[sum];
            mp[sum]++;
        }
        ll ans = n * (n + 1) / 2;
        cout << ans + c << "\n";
    }
    return 0;
}
