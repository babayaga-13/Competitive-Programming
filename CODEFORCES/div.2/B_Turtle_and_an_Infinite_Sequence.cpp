#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int x = max(0, n - m);
    ll y = n + m;
    ll ans = x | y;

    for (int i = 30; i >= 0; i--)
    {
        ll z = (1 << i);
        if (((ans >> i) & 1) == 0)
        {
            if (y - x >= z)
            {
                ans += z;
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
