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

ll inv_count(vector<int> &v, int n)
{
    pbds<int> p;
    ll count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        p.insert(v[i]);
        ll j = p.order_of_key(v[i]);
        count += j;
    }
    return count;
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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        set<int> s1, s2;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s1.insert(a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            s2.insert(b[i]);
        }
        if (s1 != s2)
        {
            no;
            continue;
        }
        ll x = inv_count(a, n);
        ll y = inv_count(b, n);
        // cout << x << " " << y << endl;
        if (x % 2 == y % 2)
            yes;
        else
            no;
    }
    return 0;
}
