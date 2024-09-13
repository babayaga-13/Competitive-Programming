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
        vector<int> v;
        if (n % 2 != 0)
        {
            for (int i = 1; i <= n / 2; ++i)
            {
                v.push_back(i);
                v.push_back(n - i);
            }
            v.push_back(n);
        }
        else
        {
            for (int i = 1; i <= n / 2; ++i)
            {
                v.push_back(i);
                v.push_back(n + 1 - i);
            }
        }
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
