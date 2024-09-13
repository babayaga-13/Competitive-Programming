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
        string s;
        cin >> s;
        ll ans = 0, f = 0, l = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                f = n - i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                l = i + 1;
                break;
            }
        }
        ans = max(f * 2, l * 2);
        ans = max(ans, n);
        cout << ans << endl;
    }
}
