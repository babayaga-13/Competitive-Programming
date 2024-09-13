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
string ans(string s, int k)
{
    string res = "";
    while (k--)
        res += s;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        int n = x.size(), m = y.size();
        int a = __gcd(n, m);
        if (ans(x, m / a) == ans(y, n / a))
            cout << ans(x, m / a) << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}
