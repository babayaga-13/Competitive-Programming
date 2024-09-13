#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<int> v(n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m = max(m, v[i]);
    }
    int x = m - v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] != m)
            x = __gcd(x, m - v[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (m - v[i]) / x;
    }
    cout << ans << " " << x;
}