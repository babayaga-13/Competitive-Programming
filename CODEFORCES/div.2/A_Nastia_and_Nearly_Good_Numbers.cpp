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
        ll a, b;
        cin >> a >> b;
        if (b == 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << a << " " << (a * b) << " " << a * b + a << endl;
        }
    }
}