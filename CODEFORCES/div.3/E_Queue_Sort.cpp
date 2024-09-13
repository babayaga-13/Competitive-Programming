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
        int n, f = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int x = min_element(v.begin(), v.end()) - v.begin();
        for (int i = x; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                cout << "-1\n";
                f++;
                break;
            }
        }
        int ans = 0;
        if (!f)
        {
            cout << x << endl;
        }
    }
    return 0;
}
