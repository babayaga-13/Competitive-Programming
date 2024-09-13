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
        int ax, ay, bx, by, cx, cy, a = 0, b = 0;
        cin >> ax >> ay >> bx >> by >> cx >> cy;

        if ((bx <= ax && cx >= ax) || (bx >= ax && cx <= ax))
        {
            no;
        }
        else if ((by <= ay && cy >= ay) || (by >= ay && cy <= ay))
            no;
        else
            yes;
    }
    return 0;
}
