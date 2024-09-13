#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll v[n];
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        ll f = 0;

        if (v[0] != v[n - 1])
            f++;
        else
        {
            for (ll i = 0; i < n; i++)
            {
                if (v[0] <= v[i])
                    continue;
                else
                {
                    f++;
                    break;
                }
            }
        }
        if (f == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
