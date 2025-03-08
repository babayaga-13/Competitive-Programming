#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define count_one(x) __builtin_popcount(x)
#define trailing_zero(x) __builtin_ctz(x)
#define leading_zero(x) __builtin_clz(x)
#define gcd __gcd
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    int i = n - 1;

    while (i >= 0)
    {
        if (s[i] == '1')
        {
            ll sum = 0, mn = INT_MAX;
            while (i >= 0 && s[i] == '1')
            {
                sum += a[i];
                mn = min(mn, a[i]);
                i--;
            }
            if (i >= 0)
            {
                mn = min(mn, a[i]);
                sum += a[i];
                ans += sum - mn;
            }
            else
                ans += sum;
        }
        i--;
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
