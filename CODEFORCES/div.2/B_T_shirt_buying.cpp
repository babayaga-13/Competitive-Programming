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
    int n;
    cin >> n;
    vector<int> p(n), vis(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[3];

    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        pq[x].push({p[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        pq[x].push({p[i], i});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;
        y--;
        while (!pq[y].empty() && vis[pq[y].top().second])
            pq[y].pop();
        if (pq[y].empty())
            cout << "-1\n";
        else
        {
            vis[pq[y].top().second] = 1;
            cout << pq[y].top().first << " ";
            pq[y].pop();
        }
    }
    return 0;
}
