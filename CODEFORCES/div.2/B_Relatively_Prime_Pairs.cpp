#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll l, h;
    cin >> l >> h;
    if (l == h)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (ll i = l; i < h; i += 2)
        cout<< i << " " << i + 1 << endl;
}