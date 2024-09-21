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

        vector<vector<int>> v(26);
        for (int i = 0; i < n; i++)
        {
            v[a[i] - 'a'].push_back(i);
        }
        vector<string> st;
        for (int i = 0; i < m; i++)
        {
            string x;
            for (int j = i; j < m; j++)
            {
                x += b[j];
                st.push_back(x);
            }
        }

        int ans = n + m;
        for (auto &y : st)
        {
            int z = -1;
            bool found = true;

            for (char k : y)
            {
                auto it = upper_bound(v[k - 'a'].begin(), v[k - 'a'].end(), z);

                if (it == v[k - 'a'].end())
                {
                    found = false;
                    break;
                }
                else
                {
                    z = *it;
                }
            }

            if (found)
            {
                ans = min(ans, n + m - (int)y.size());
            }
        }
        cout << ans << endl;

        // int ans = n + m;
        // for (int i = 0; i < m; i++)
        // {
        //     int c = 0, indx = i;
        //     for (int j = 0; j < n && indx < m; j++)
        //     {
        //         if (a[j] == b[indx])
        //         {
        //             c++;
        //             indx++;
        //         }
        //     }
        //     ans = min(ans, n + m - c);
        // }
        // cout << ans << endl;
    }

    return 0;
}
