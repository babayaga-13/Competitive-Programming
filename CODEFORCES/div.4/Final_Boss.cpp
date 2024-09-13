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
        ll h, n;
        cin >> h >> n;
        vector<ll> a(n), c(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];

        for (int j = 0; j < n; ++j)
            cin >> c[j];

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (int j = 0; j < n; ++j)
            pq.push({1, j});

        ll ans = 0;
        while (h > 0)
        {
            ans = pq.top().first;
            while (!pq.empty() && pq.top().first == ans)
            {
                int idx = pq.top().second;
                pq.pop();
                h -= a[idx];
                pq.push(make_pair(ans + c[idx], idx));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
