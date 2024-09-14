#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll c, ll n, ll m)
{
    ll sum = (c * (c + 1)) / 2;
    return (n + sum) <= m;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll l = 0, h = 1e5, ans = 0;

    while (l <= h)
    {
        ll mid = (l + h) / 2;

        if (check(mid, n, m))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << ans + 1 << endl;
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
