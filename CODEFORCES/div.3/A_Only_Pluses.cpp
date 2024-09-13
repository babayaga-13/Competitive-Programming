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
        ll a[3];
        for (int i = 0; i < 3; i++)
            cin >> a[i];
        ll ans = 0;
        for (int i = 0; i <= 5; i++)
        {
            for (int j = 0; j <= 5 - i; j++)
            {
                ll b[3] = {a[0] + i, a[1] + j, a[2] + (5 - i - j)};
                ans = max(ans, b[0] * b[1] * b[2]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
