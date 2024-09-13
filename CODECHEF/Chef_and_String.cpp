#include <bits/stdc++.h>
#define ll long long
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
        ll c = 0, b = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if ((s[i] == 'x' && s[i + 1] == 'y') || (s[i] == 'y' && s[i + 1] == 'x'))
            {
                c++;
                i++;
            }
        }
        cout << c << endl;
    }
}