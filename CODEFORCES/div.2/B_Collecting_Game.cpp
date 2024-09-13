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
        int n;
        cin >> n;
        vector<pair<ll, ll>> v(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back({x, i});
        }
        sort(v.rbegin(), v.rend());
        vector<ll> p(n), ans(n, 0);
        p[n - 1] = v[n - 1].first;
        for (int i = n - 2; i >= 0; i--)
        {
            p[i] = v[i].first + p[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            int x = v[i].second;
            if (i == 0)
            {
                ans[x] = n - i - 1;
                continue;
            }
            if (p[i] >= v[i - 1].first)
                ans[x] = ans[v[i - 1].second];
            else
                ans[x] = n - i - 1;
        }
        
        for (auto u : ans)
            cout << u << " ";
        ln;
    }
}
