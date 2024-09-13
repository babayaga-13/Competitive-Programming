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
        string x, y;
        cin >> x >> y;
        int n = x.size();
        bool f = true;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '0' && y[i] == '0' && x[i + 1] == '1' && y[i + 1] == '1')
            {
                cout << "YES\n";
                f = false;
                break;
            }
        }
        if (f)
            cout << "NO\n";
    }
}