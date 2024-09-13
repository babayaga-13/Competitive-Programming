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
        int a[n], b[n], c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
                x += a[i];
            else if (b[i] > a[i])
                y += b[i];
            else
            {
                if (a[i] == 1)
                    c1++;
                if (a[i] == -1)
                    c2++;
            }
        }
        while (c1--)
        {
            if (x > y)
                y++;
            else
                x++;
        }
        while (c2--)
        {
            if (x > y)
                x--;
            else
                y--;
        }
        cout << min(x, y) << endl;
    }
    return 0;
}
