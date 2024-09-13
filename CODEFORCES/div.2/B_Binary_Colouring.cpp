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

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        vector<int> v;
        while (x > 0)
        {
            if ((x & 1) == 1 && (x & 2) == 2)
            {
                v.push_back(-1);
                x++;
            }
            else
            {
                v.push_back(x & 1);
            }
            x >>= 1;
        }

        cout << v.size() << endl;
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }

    return 0;
}
