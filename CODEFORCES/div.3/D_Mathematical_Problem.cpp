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
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 2)
        {
            cout << stoi(s) << endl;
            continue;
        }
        int ans = INT_MAX;
        bool flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    if (((s[j] - '0') * 10 + (s[j + 1] - '0')) == 1)
                    {
                        j++;
                        continue;
                    }
                    sum += ((s[j] - '0') * 10 + (s[j + 1] - '0'));
                    j++;
                }
                else
                {
                    if (s[j] == '0')
                        flag = true;
                    else if (s[j] == '1')
                        continue;
                    else
                        sum += (s[j] - '0');
                }
            }
            if (sum == 0)
                sum = 1;
            if (flag)
                sum = 0;

            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}
