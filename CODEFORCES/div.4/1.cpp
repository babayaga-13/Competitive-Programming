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
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        int left = 1, right = 1000000;
        int result = right;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            double s1 = 2.0 * x * (1.0 - pow(0.5, mid));
            long long s2 = y * mid;

            if (s2 > s1)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}
