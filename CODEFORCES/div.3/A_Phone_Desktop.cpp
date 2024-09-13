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
        ll ans = (y + 1) / 2;
        ll cell = 15 * ans;
        cell -= y * 4;
        if (cell >= x)
            cout << ans << endl;
        else
        {
            x -= cell;
            ans += ceil((float)x / 15);
            cout << ans << endl;
        }
    }
}