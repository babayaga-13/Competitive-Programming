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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[0] += 1;
            if (a[i] < n)
                b[a[i]] -= 1;
        }
        if (a[0] != n)
        {
            no;
            continue;
        }

        for (int i = 1; i < n; i++)
        {
            b[i] += b[i - 1];
        }
        if (a == b)
            yes;
        else
            no;
    }
    return 0;
}