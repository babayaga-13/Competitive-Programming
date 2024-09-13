#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
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
        char a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        ll ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] == '.' && b[i] == '.')
            {
                if (a[i - 1] == 'x' && a[i + 1] == 'x' && b[i - 1] == '.' && b[i + 1] == '.')
                    ans++;
                if (b[i - 1] == 'x' && b[i + 1] == 'x' && a[i - 1] == '.' && a[i + 1] == '.')
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
