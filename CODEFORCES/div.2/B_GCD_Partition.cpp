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
        ll n;
        cin >> n;
        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            v[i] += v[i - 1];
        }
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, __gcd(v[i], v[n] - v[i]));
        }
        cout << ans << endl;
    }
}