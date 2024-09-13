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
        int n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        priority_queue<int> q;
        for (auto u : mp)
        {
            q.push(u.second);
        }

        while (q.size() >= 2)
        {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();

            x--;
            y--;
            n -= 2;

            if (x > 0)
            {
                q.push(x);
            }
            if (y > 0)
            {
                q.push(y);
            }
        }

        cout << n << "\n";
    }

    return 0;
}
