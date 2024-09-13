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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int ans = min(v[0], v[1]);
        if (n == 2)
        {
            cout << ans << endl;
            continue;
        }

        for (int i = 0; i <= n - 3; i++)
        {
            vector<int> x;
            for (int j = i; j < i + 3; j++)
            {
                x.push_back(v[j]);
            }
            sort(x.begin(), x.end());
            ans = max(ans, x[1]);
        }
        cout << ans << endl;
    }
}
