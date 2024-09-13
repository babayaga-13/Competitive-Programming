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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<pair<int, int>> v;
        int f = -1;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] != a[1])
            {
                f = i;
                v.push_back({1, i});
            }
        }
        if (f == -1)
        {
            no;
            continue;
        }
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] == a[1])
            {
                v.push_back({f, i});
            }
        }
        yes;
        for (auto u : v)
            cout << u.first << " " << u.second << endl;
    }
    return 0;
}
