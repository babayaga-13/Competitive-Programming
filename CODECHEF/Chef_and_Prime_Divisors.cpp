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
        ll a, b, f = 0;
        cin >> a >> b;
        if (a == b)
        {
            cout << "Yes" << endl;
            continue;
        }
        while (b > 1)
        {
            ll g = __gcd(a, b);
            if (g == 1)
            {
                cout << "No\n";
                f++;
                break;
            }
            b = b / g;
        }
        if (f == 0)
            cout << "Yes\n";
    }
}