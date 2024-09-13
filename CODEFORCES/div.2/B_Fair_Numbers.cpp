#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    while (1)
    {
        int x = n;
        bool f = true;
        while (x > 0)
        {
            int d = x % 10;
            if (d != 0 && n % d != 0)
            {
                f = false;
                break;
            }
            x /= 10;
        }
        if (f)
        {
            cout << n << endl;
            return;
        }
        n++;
    }
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
