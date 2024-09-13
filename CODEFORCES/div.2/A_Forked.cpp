#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
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
        int a, b;
        cin >> a >> b;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        vector<pair<int, int>> d = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
        set<pair<int, int>> s;
        for (int i = 0; i < 8; i++)
        {
            int a = x1 + d[i].first;
            int b = y1 + d[i].second;
            for (int j = 0; j < 8; j++)
            {
                if ((a + d[j].first == x2) && (b + d[j].second == y2))
                    s.insert({a, b});
            }
        }
        int ans = s.size();
        cout << ans << endl;
    }
    return 0;
}
