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
        int n;
        cin >> n;
        vector<int> v(n);
        bool all_zeros = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] != 0)
            {
                all_zeros = false;
            }
        }
        if (all_zeros)
        {
            cout << "0\n";
            continue;
        }

        int l = 0, r = n - 1;
        while (l < n && v[l] == 0)
            l++;
        while (r >= 0 && v[r] == 0)
            r--;

        bool f = true;
        for (int i = l; i <= r; i++)
        {
            if (v[i] == 0)
            {
                f = false;
                break;
            }
        }

        if (f)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }
    return 0;
}
