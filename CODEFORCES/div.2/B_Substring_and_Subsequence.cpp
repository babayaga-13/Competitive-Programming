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
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int ans = n + m;
        for (int i = 0; i < m; i++)
        {
            int c = 0, indx = i;
            for (int j = 0; j < n && indx < m; j++)
            {
                if (a[j] == b[indx])
                {
                    c++;
                    indx++;
                }
            }
            ans = min(ans, n + m - c);
        }
        cout << ans << endl;
    }

    return 0;
}
