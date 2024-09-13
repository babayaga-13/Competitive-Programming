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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }
        int f = 0;
        for (int i = 0; i <= n; i++)
        {
            if (mp[i] == 0)
            {
                cout << i << endl;
                break;
            }
            else
            {
                if (mp[i] == 1)
                {
                    f++;
                    if (f == 2)
                    {
                        cout << i << endl;
                        break;
                    }
                }
            }
        }
    }
}