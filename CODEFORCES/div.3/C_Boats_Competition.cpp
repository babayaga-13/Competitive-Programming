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
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[x]++;
        }
        int ans = 0;
        for (int i = 2; i <= 2 * n; i++)
        {
            int c = 0;
            for (int j = 1; j < (i + 1) / 2; j++)
            {
                if (i - j > n)
                    continue;
                c += min(v[j], v[i - j]);
            }
            if (i % 2 == 0)
            {
                c += v[i / 2] / 2;
            }
            ans = max(ans, c);
        }
        cout << ans << endl;
    }
    return 0;
}
