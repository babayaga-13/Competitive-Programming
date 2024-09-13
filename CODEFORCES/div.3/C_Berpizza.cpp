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
    priority_queue<pair<int, int>> pq;
    int indx = 1, i = 1;
    vector<int> v(t + 1, 0);
    v[0] = 1;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int m;
            cin >> m;
            pq.push({m, -indx});
            indx++;
        }
        else if (n == 2)
        {
            while (v[i] == 1)
            {
                i++;
            }
            v[i] = 1;
            cout << i << " ";
        }
        else if (n == 3)
        {
            while (v[-pq.top().second] == 1)
            {
                pq.pop();
            }
            v[-pq.top().second] = 1;
            cout << -pq.top().second << " ";
            pq.top();
        }
    }
    return 0;
}
