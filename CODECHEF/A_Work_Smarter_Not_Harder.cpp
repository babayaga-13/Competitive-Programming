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
        ll l, a, b;
        cin >> l >> a >> b;
        a = ceil((float)l / a);
        b = ceil((float)l / b);

        if (a - b - 1 >= 0)
            cout << a - b - 1 << endl;
        else
            cout << "-1\n";
    }
}