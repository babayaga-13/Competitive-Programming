#include <bits/stdc++.h>
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
        string s;
        cin >> s;
        string ans;
        ans += s[0];
        bool f = false;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1] && f == false)
            {
                char c;
                if (s[i] == 'z')
                {
                    c = 'a';
                }
                else
                {
                    c = s[i] + 1;
                }
                ans += c;
                f = true;
            }
            ans += s[i];
        }

        if (!f)
        {
            char c;
            if (s[0] == 'z')
                c = 'a';
            else
                c = s[0] + 1;
            ans = c + ans;
        }

        cout << ans << endl;
    }
    return 0;
}
