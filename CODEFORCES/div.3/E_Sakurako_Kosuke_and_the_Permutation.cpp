#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1); // Using 1-based index
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<bool> visited(n + 1, false);
    int swaps = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int cycle_size = 0;
            int x = i;
            while (!visited[x])
            {
                visited[x] = true;
                x = p[x];
                cycle_size++;
            }
            // If the cycle size is greater than 1, we can fix it with (cycle_size - 1) swaps
            if (cycle_size > 1)
            {
                swaps += (cycle_size - 1);
            }
        }
    }

    cout << swaps << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
