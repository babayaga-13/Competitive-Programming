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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int x = 0;
        int m = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            int z = v[i] - v[i - 1];
            if (z < m)
            {
                m = z;
                x = i;
            }
        }
        if (n == 2)
            x = 0;
        for (int i = x; i < n; i++)
            cout << v[i] << " ";
        for (int i = 0; i < x; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}
