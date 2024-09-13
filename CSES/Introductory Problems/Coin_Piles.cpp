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
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        if ((x + y) % 3 == 0 && x >= ((y + 1) / 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
