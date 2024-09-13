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
        int n, m;
        cin >> n >> m;
        int a = n, b = 1, c = m, d = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char s;
                cin >> s;
                if (s == '#')
                {
                    a = min(a, i);
                    b = max(b, i);
                    c = min(c, j);
                    d = max(d, j);
                }
            }
        }
        cout << (b + a + 1) / 2 << " " << (d + c + 1) / 2 << endl;
    }
    return 0;
}
