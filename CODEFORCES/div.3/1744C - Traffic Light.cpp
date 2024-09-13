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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;
        s = s + s;
        int ans = 0, f = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                while (s[i] != 'g' && i < s.size())
                {
                    f++;
                    i++;
                }
            }
            if (f > ans)
                ans = f;

            f = 0;
        }
        cout << ans << endl;
    }
}
