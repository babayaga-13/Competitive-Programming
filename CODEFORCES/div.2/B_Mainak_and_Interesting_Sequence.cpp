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
        int n, m;
        cin >> n >> m;
        if (n > m)
            no;
        else if (n % 2 == 1)
        {
            yes;
            for (int i = 1; i < n; i++)
                cout << "1 ";
            cout << (m - n + 1) << endl;
        }
        else
        {
            if (m % 2 == 0)
            {
                yes;
                for (int i = 1; i < n - 1; i++)
                    cout << "1 ";
                cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << endl;
            }
            else
                no;
        }
    }
    return 0;
}
