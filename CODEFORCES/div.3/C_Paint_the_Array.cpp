#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
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
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        ll a = v[0], b = v[1];
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                a = __gcd(a, v[i]);
            }
            else
            {
                b = __gcd(b, v[i]);
            }
        }
        ll f = 0, g = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (v[i] % b == 0)
                {
                    f++;
                    break;
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 != 0)
            {
                if (v[i] % a == 0)
                {
                    g++;
                    break;
                }
            }
        }
        if (f == 0)
            cout << b << endl;
        else if (g == 0)
            cout << a << endl;
        else
            cout << "0\n";
    }
}