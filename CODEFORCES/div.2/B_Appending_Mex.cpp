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
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int c = 1, ans = -1;
        if (a[0] != 0)
        {
            cout << "1\n";
            break;
        }
        bool f = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= c)
            {
                c = max(c, a[i] + 1);
            }
            else
            {
                f = false;
                cout << i + 1 << endl;
                break;
            }
        }
        if (f)
            cout << "-1\n";
    }
    return 0;
}
