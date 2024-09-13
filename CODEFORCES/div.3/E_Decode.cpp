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
const int N = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        ll a[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                a[i + 1] = 1;
            else
                a[i + 1] = -1;
            a[i + 1] += a[i];
        }
        map<int, ll> mp;
        mp[0] = 1;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + (n - i + 1) * mp[a[i]]) % N;
            // cout << (n - i + 1) << " " << mp[a[i]] << endl;
            mp[a[i]] = (mp[a[i]] + (i + 1)) % N;
        }

        cout << ans << endl;
    }

    return 0;
}
