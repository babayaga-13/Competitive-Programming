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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        vector<pair<int, int>> a(k + 1);
        int l = 0, h = n - 1, c = 1;
        while (l <= h)
        {
            if (v[l] >= c && v[h] >= c)
            {
                a[c] = {l, h};
                c++;
            }
            else if (v[l] < c)
                l++;
            else if (v[h] < c)
                h--;
        }
        for (int i = 1; i <= k; i++)
        {
            if (mp[i] > 0)
                cout << (a[i].second - a[i].first + 1) * 2 * 1LL << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
