#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string x, y;
        cin >> x >> y;
        int ans = INT_MAX;

        for (int i = 0; i <= n - m; i++)
        {
            int s = 0;
            for (int j = 0; j < m; j++)
            {
                s += min(abs(x[i + j] - y[j]), abs(10 - abs(x[i + j] - y[j])));
            }
            ans = min(ans, s);
        }
        cout << ans << endl;
    }
}