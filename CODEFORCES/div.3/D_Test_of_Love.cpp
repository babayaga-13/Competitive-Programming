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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        m--;
        int x = m, y = 0;
        bool f = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                x = m;
            else if (s[i] == 'W')
            {
                if (x <= 0)
                    k--;
                x--;
            }
            else
            {
                if (x <= 0)
                {
                    f = true;
                    break;
                }
                x--;
            }
            if (k < 0)
            {
                f = true;
                break;
            }
        }
        if (f)
            no;
        else
            yes;
    }
    return 0;
}