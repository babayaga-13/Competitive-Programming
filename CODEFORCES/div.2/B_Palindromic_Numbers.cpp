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
vector<int> v = {0, 9, 99, 999, 9999, 99999, 999999, 9999999};
vector<int> a = {0, 11, 121, 1221, 12221, 122221, 1222221, 12222221};
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
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            char a;
            cin >> a;
            num[i] = a - '0';
        }
        vector<int> ans(n);
        if (num[0] < 9)
        {
            for (int i = 0; i < n; i++)
                cout << 9 - num[i];
            cout << "\n";
        }
        else
        {
            bool carry = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                int cur = 1;
                if (carry)
                {
                    cur = 0;
                    carry = 0;
                }
                if (num[i] > cur)
                {
                    cur += 10;
                    carry = 1;
                }
                ans[i] = cur - num[i];
            }
            for (int i = 0; i < n; i++)
                cout << ans[i];
            cout << "\n";
        }
    }
    return 0;
}
