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

        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int l = 0, h = 0;
        pbds<pair<int, int>> p;
        while (h < n)
        {
            p.insert({a[h], h});
            if (h - l + 1 == k)
            {
                int pos = (k - 1) / 2;
                auto it = p.find_by_order(pos);
                cout << it->first << " ";
                p.erase({a[l], l});
                l++;
            }
            h++;
        }
        cout << '\n';
    }
    return 0;
}
