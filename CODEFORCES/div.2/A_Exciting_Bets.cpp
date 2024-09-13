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
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (n == m)
            cout << "0 0\n";
        else if (abs(n - m) == 1)
            cout << "1 0\n";
        else
        {
            ll x = abs(n - m);
            ll y = min(n % x, x - (n % x));
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
