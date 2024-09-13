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
    // cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<pair<char, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({s[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k; i++)
        {
            int x = v[i].second;
            s[x] = '0';
        }
        for (auto u : s)
        {
            if (u != '0')
                cout << u;
        }
        cout << endl;
        return 0;
    }
}
