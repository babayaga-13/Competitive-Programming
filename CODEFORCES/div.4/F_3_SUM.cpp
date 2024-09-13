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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x %= 10;
            mp[x]++;
            if (mp[x] <= 3)
                v.push_back(x);
        }
        int m = v.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                for (int k = j + 1; k < m; k++)
                {
                    if ((v[i] + v[j] + v[k]) % 10 == 3)
                    {
                        yes;
                        goto next;
                    }
                }
            }
        }
        no;
    next:
        continue;
    }
    return 0;
}
