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
        bool f = false;
        for (int i = 1; i < n; i++)
        {
            if (abs(v[i] - v[i - 1]) >= 2)
            {
                cout << "YES\n";
                cout << i << " " << i + 1 << endl;
                f = true;
                break;
            }
        }
        if (!f)
            cout << "NO\n";
    }
}
