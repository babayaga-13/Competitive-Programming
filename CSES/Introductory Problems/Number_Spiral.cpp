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
        ll x, y;
        cin >> x >> y;
        ll ans = 1;
        if (x > y)
        {
            if (x % 2 == 0)
                ans = x * x - (y - 1);
            else
                ans = (x - 1) * (x - 1) + 1 + (y - 1);
        }
        else
        {
            if (y % 2 != 0)
                ans = y * y - (x - 1);
            else
                ans = (y - 1) * (y - 1) + 1 + (x - 1);
        }
        cout << ans << endl;
    }
}