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
        ll a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) % 2 != 0)
            cout << "-1\n";
        else
        {
            cout << min((a + b + c) / 2, (a + b)) << endl;
        }
    }
}