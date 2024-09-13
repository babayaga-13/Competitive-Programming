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
        vector<int> a(n), b(n);
        map<int, int> mp1, mp2, mp3;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp1[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mp2[b[i]]++;
        }
        int m;
        cin >> m;
        vector<int> c(m);
        for (int i = 0; i < m; i++)
        {
            cin >> c[i];
            mp3[c[i]]++;
        }
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                continue;
            else
            {
                if (mp3[b[i]] > 0)
                    mp3[b[i]]--;
                else
                {
                    f++;
                    break;
                }
            }
        }
        int g = 0;
        for (int i = 0; i < n; i++)

            if (b[i] == c[m - 1])
            {
                g++;
                break;
            }
        if (!f && g)
            yes;
        else
            no;
    }
    return 0;
}
