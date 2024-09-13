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
        vector<ll> v(1001, 0);
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            v[x] = i;
        }
        ll ans = -1;
        for (int i = 1; i < 1001; i++)
        {
            for (int j = 1; j < 1001; j++)
            {
                if (v[i] != 0 && v[j] != 0 && __gcd(i, j) == 1)
                    ans = max(ans, v[i] + v[j]);
            }
        }
        cout << ans << endl;
    }
}