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
        vector<int> v(n), v1, v2, v3;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<int> a;
        for (int i = 0; i < n - 1; i++)
        {
            int x = __gcd(v[i], v[i + 1]);
            a.push_back(x);
        }

        int f = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] > a[i + 1])
            {
                f = i + 1;
                break;
            }
        }

        if (f == 0)
        {
            yes;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (i != f)
            {
                v1.push_back(v[i]);
            }
            if (i != f + 1)
            {
                v2.push_back(v[i]);
            }
            if (i != f - 1)
            {
                v3.push_back(v[i]);
            }
        }

        bool c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < n - 3; i++)
        {
            if (__gcd(v1[i], v1[i + 1]) > __gcd(v1[i + 1], v1[i + 2]))
            {
                c1 = 1;
                break;
            }
        }
        for (int i = 0; i < n - 3; i++)
        {
            if (__gcd(v2[i], v2[i + 1]) > __gcd(v2[i + 1], v2[i + 2]))
            {
                c2 = 1;
                break;
            }
        }
        for (int i = 0; i < n - 3; i++)
        {
            if (__gcd(v3[i], v3[i + 1]) > __gcd(v3[i + 1], v3[i + 2]))
            {
                c3 = 1;
                break;
            }
        }

        if (c1 && c2 && c3)
        {
            no;
        }
        else
        {
            yes;
        }
    }
    return 0;
}