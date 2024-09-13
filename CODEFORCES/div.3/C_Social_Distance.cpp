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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0, f = -1, l = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                f = i;
                break;
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (s[i] == '1')
            {
                l = i;
                break;
            }
        }
        if (l == -1 && f == -1)
        {
            cout << (n / k) << endl;
            continue;
        }

        cout << ans << endl;
    }
    return 0;
}