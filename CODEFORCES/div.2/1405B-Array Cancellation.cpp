#include <bits/stdc++.h>
#define ll long long
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
        ll n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            ans = max(0LL, ans + x);
        }
        cout << ans << endl;
    }
}
