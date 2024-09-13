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
        int x = 31 - __builtin_clz(n);
        vector<int> ans;
        ans.push_back(n);
        for (int i = 0; i < x; i++)
        {
            if (n & (1 << i))
            {
                n -= (1 << i);
                ans.push_back(n);
            }
        }
        while (n > 1)
        {
            n >>= 1; // n/=2;
            ans.push_back(n);
        }
        cout << ans.size() << endl;
        for (auto u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
