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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool ans = true;
        for (int i = 1; i <= n; i++)
        {
            bool found = false;
            for (int j = i + 1; j >= 2; j--)
            {
                if (a[i] % j)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}