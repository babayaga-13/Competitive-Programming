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
        vector<int> a(n + 1, 0), c(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1')
                a[i] = 1;
        }
        long long ans = 0;
        for (int i = n; i > 0; i--)
        {
            for (int j = i; j <= n; j += i)
            {
                if (a[j])
                    break;
                c[j] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!a[i])
                ans += c[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
