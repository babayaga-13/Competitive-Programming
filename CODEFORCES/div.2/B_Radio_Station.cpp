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
    int n, m;
    cin >> n >> m;
    n += m;
    map<string, string> mp;
    while (n--)
    {
        string x, y;
        cin >> x >> y;
        if (y.back() == ';')
        {
            y.pop_back();
            cout << x << " " << y << "; " << mp[y] << endl;
        }
        else
            mp[y] = ('#' + x);
    }
    return 0;
}
