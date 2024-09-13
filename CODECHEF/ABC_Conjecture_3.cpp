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
        string s;
        cin >> s;
        int a = 0, ta = 0, b = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a++;
            else if (s[i] == 'b')
            {
                ta += a;
                b = 1;
                a = 0;
            }
            else if (s[i] == 'c')
            {
                if (b > 0 && ta > 0)
                {
                    ans++;
                    ta--;
                }
            }
        }
        cout << ans << endl;
    }
}