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
        ll n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int ans = 1;

        for (int i = 0; i < 20; i++)
        {
            int c = 1;
            int f = 0;
            for (int j = 0; j < n; j++)
            {
                if (v[j] & (1 << i))
                {
                    ans = max(ans, c);
                    c = 1;
                    f++;
                }
                else
                    c++;
            }
            if (f)
                ans = max(ans, c);
        }
        cout << ans << endl;
    }
}