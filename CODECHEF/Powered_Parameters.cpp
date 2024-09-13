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
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 1)
                ans += n;
            else
            {
                for (int j = 1; j <= n; j++)
                {
                    ll x = pow(v[i], j);
                    if (x > 1e9)
                        break;
                    if (x <= v[j])
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
