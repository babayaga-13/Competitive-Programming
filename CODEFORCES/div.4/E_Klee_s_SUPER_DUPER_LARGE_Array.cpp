#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll check(ll i, ll k, ll tot)
{
    ll s = (i * (2 * k + (i - 1))) / 2;
    return abs(2 * s - tot);
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll tot = n * (2 * k + (n - 1)) / 2;

    ll l = 1, r = n, ans = LLONG_MAX;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll x1 = check(mid, k, tot);
        ll x2 = check(mid + 1, k, tot);
        ans = min(ans, x1);

        if (x1 < x2)
            r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
