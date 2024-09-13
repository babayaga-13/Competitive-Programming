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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int x, y, z;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
                x = i;
            if (v[i] == 2)
                y = i;
            if (v[i] == (n))
                z = i;
        }
        if (z > min(x, y) && z < max(x, y))
        {
            cout << x + 1 << " " << y + 1 << endl;
        }
        else if (z > min(x, y) && z > max(x, y))
        {
            cout << z + 1 << " " << max(x, y) + 1 << endl;
        }
        else if (z < min(x, y) && z < max(x, y))
        {
            cout << z + 1 << " " << min(x, y) + 1 << endl;
        }
    }
}