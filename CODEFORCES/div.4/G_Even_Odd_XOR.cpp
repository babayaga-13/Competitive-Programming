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
        int x1 = 0;
        int x2 = 0;
        for (int i = 0; i < n - 2; i++)
        {
            x1 ^= i;
            x2 ^= (i + 1);
        }
        int s = ((long long)1 << 20) - 1;
        if (x1 != 0)
        {
            for (int i = 0; i < n - 2; i++)
            {
                cout << i << " ";
            }
            x1 ^= s;
            cout << s << " " << x1 << endl;
        }
        else
        {
            for (int i = 1; i <= n - 2; i++)
            {
                cout << i << " ";
            }
            x2 ^= s;
            cout << s << " " << x2 << endl;
        }
    }
    return 0;
}
