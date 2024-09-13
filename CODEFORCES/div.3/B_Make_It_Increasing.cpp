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
        int a[n];
        ll ans = 0;
        bool f = false;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            while (a[i] >= a[i + 1])
            {
                a[i] /= 2;
                ans++;
                if (a[i] <= 0)
                    break;
            }
            if ((a[i] == 0 && i != 0) || a[i] == a[i + 1])
            {
                f = true;
                break;
            }
        }
        if (f)
            cout << "-1\n";
        else
            cout << ans << endl;
    }
    return 0;
}
