#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        char x = s[i];
        mp[x]++;
    }
    int c = 0;
    string ans = "", y = "";
    for (auto u : mp)
    {
        if (u.second % 2 == 0)
        {
            for (int i = 0; i < u.second / 2; i++)
            {
                ans += u.first;
            }
        }
        else
        {
            c++;
            for (int i = 0; i < u.second / 2; i++)
            {
                ans += u.first;
            }
            y = u.first;
        }
    }
    string ans2 = ans;
    reverse(ans2.begin(), ans2.end());
    if (c > 1)
        cout << "NO SOLUTION";
    else
        cout << ans + y + ans2;
}