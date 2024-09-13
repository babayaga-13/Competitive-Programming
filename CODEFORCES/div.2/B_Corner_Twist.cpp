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
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        vector<string> vec1(x), vec2(x);
        for (int i = 0; i < x; i++)
            cin >> vec1[i];
        for (int i = 0; i < x; i++)
            cin >> vec2[i];
        for (int i = 0; i < x - 1; i++)
        {
            for (int j = 0; j < y - 1; j++)
            {
                if (vec1[i][j] != vec2[i][j])
                {
                    int s = (vec2[i][j] - vec1[i][j] + 3) % 3;
                    vec1[i][j] = vec2[i][j];
                    vec1[i + 1][j + 1] = ((vec1[i + 1][j + 1] - '0' + s) % 3) + '0';
                    vec1[i + 1][j] = ((vec1[i + 1][j] - '0' + 2 * s) % 3) + '0';
                    vec1[i][j + 1] = ((vec1[i][j + 1] - '0' + 2 * s) % 3) + '0';
                }
            }
        }
        bool p = true;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (vec1[i][j] != vec2[i][j])
                {
                    p = false;
                    goto f;
                }
            }
        }
    f:
        if (p)
            yes;
        else
            no;
    }
    return 0;
}
