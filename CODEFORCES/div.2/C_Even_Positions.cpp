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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
<<<<<<< HEAD
        ll ans = 0;
        for (int i = 2; i <= n; i += 2)
        {
            if (i % 2 == 0)
            {
                // if (i == 1 || s[i - 1] == ')')
                //     s[i] = '(';
                // else
                //     s[i] = ')';
                if (s[i] == '(')
                    ans += 3;
                else
                    ans++;
            }
        }

        // vector<int> a;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (s[i] == '(')
        //         a.push_back(i);
        //     else if (s[i] == ')')
        //     {
        //         ans += i - a.back();
        //         a.pop_back();
        //     }
        // }
=======
        for (int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                if (i == 1 || s[i - 1] == ')')
                    s[i] = '(';
                else
                    s[i] = ')';
            }
        }
        ll ans = 0;
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '(')
                a.push_back(i);
            else if (s[i] == ')')
            {
                ans += i - a.back();
                a.pop_back();
            }
        }
>>>>>>> bdf6a2f2a55972e1c0c0170b5584b3cd6b1e91f2
        cout << ans << endl;
    }

    return 0;
}
