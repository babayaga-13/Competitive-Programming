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
        int n, k, d;
        cin >> n >> k >> d;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = INT_MAX;
        set<int> s;
        map<int, int> mp;
        int l = 0, h = 0;
        while (h < n)
        {
            s.insert(a[h]);
            mp[a[h]]++;
            if (h - l + 1 >= d)
            {
                ans = min(ans, (int)s.size());
                mp[a[l]]--;
                if (mp[a[l]] == 0)
                {
                    s.erase(a[l]);
                }
                l++;
            }
            h++;
        }
        cout << ans << endl;
    }
    return 0;
}
