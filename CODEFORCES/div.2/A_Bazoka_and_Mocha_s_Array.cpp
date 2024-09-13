#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int f = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] < a[i])
            {
                f++;
            }
        }
        if (f == 0)
        {
            yes;
            continue;
        }
        if (a[n - 1] > a[0] || f > 1)
        {
            no;
            continue;
        }
        yes;
    }

    return 0;
}
