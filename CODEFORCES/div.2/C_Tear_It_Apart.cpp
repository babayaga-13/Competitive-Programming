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
        string s;
        cin >> s;
        int n = s.size();
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            int count = 0, m = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == c)
                {
                    m = max(m, count);
                    count = 0;
                }
                else
                    count++;
            }
            m = max(m, count);
            ans = min(ans, m);
        }
        if (ans == 0)
            cout << "0\n";
        else
            cout << 32 - __builtin_clz(ans) << endl;
    }
    return 0;
}
