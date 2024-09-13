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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int x = 0, y = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                while (i > 0 && b[i] >= b[i - 1])
                    i--;
                x = i + 1;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] != b[i])
            {
                while (i < n - 1 && b[i] <= b[i + 1])
                    i++;
                y = i + 1;
                break;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
