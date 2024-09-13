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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> c[i];

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (int i = 0; i < n; i++)
            pq.push({1, i});

        ll ans = 0;
        while (h > 0)
        {
            ans = pq.top().first;
            int x = pq.top().second;
            pq.pop();
            h -= a[x];
            pq.push({ans + c[x], x});
        }
        cout << ans << endl;
    }

    return 0;
}