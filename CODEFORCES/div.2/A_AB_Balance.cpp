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
        string s;
        cin >> s;
        int n = s.size();
        int x = 0, y = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'a' && s[i + 1] == 'b')
                x++;
            if (s[i] == 'b' && s[i + 1] == 'a')
                y++;
        }
        if (x == y)
            cout << s << endl;
        else
        {
            if (x > y)
            {
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == 'a')
                    {
                        s[i] = 'b';
                        break;
                    }
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == 'b')
                    {
                        s[i] = 'a';
                        break;
                    }
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}
