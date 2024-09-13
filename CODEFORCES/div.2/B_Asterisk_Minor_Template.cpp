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
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        if (a == b)
        {
            yes;
            cout << a << endl;
            continue;
        }
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    if ((i == 0 && j == 0))
                    {
                        yes;
                        cout << a[i] << "*\n";
                        goto r;
                        f = true;
                    }

                    else if ((i == (n - 1) && j == m - 1))
                    {
                        yes;
                        cout << "*" << a[i] << endl;
                        goto r;
                        f = true;
                    }
                    else if (a[i + 1] == b[j + 1])
                    {
                        yes;
                        cout << "*" << a[i] << a[i + 1] << "*\n";
                        f = true;
                        goto r;
                    }
                }
            }
        }
        if (!f)
            no;
    r:
        continue;
    }
    return 0;
}
