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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n + 1][26] = {0}, b[n + 1][26] = {0};
        char c;

        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            a[i][c - 'a']++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            b[i][c - 'a']++;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                a[i][j] += a[i - 1][j];
                b[i][j] += b[i - 1][j];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int dif = 0;
            for (int c = 0; c < 26; c++)
            {
                int v1 = a[r][c] - a[l - 1][c];
                int v2 = b[r][c] - b[l - 1][c];
                dif += abs(v1 - v2);
            }
            cout << dif / 2 << "\n";
        }
    }
    return 0;
}
