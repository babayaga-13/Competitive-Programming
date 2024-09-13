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
        priority_queue<pair<int, int>> pq;
        int n;
        cin >> n;
        int a[n + 1];
        pq.push({n, -1});
        int c = 1;
        while (!pq.empty())
        {
            int x = pq.top().first;
            int l = pq.top().second * -1;
            int r = l + x - 1;
            pq.pop();
            int mid = (l + r) / 2;
            a[mid] = c;
            c++;

            int l1, l2, r1, r2;
            l1 = l;
            r2 = r;
            r1 = mid - 1;
            l2 = mid + 1;
            if (l1 <= r1)
                pq.push({r1 - l1 + 1, -l1});
            if (l2 <= r2)
                pq.push({r2 - l2 + 1, -l2});
        }

        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}