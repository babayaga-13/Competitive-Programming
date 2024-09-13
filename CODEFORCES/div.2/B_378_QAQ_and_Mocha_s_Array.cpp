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
        sort(v.begin(), v.end());
        int x = v[0], y;
        bool f = true, f1 = true;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % x != 0 && f == true)
            {
                y = v[i];
                f = false;
            }
            else if (v[i] % x != 0 && v[i] % y != 0)
            {
                cout << "No\n";
                f1 = false;
                break;
            }
        }
        if (f1)
            cout << "Yes\n";
    }
}