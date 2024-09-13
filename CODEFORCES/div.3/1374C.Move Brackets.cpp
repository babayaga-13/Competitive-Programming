#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int st = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st++;
            else
            {
                st--;
                if (st < 0)
                {
                    st = 0;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
