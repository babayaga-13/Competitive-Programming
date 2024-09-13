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
        string x;
        cin >> x;
        string y = x;
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        map<char, char> mp;
        int l = y.length();
        for (int i = 0; i < l; ++i)
        {
            mp[y[i]] = y[l - 1 - i];
        }
        string s = x;
        for (int i = 0; i < n; ++i)
        {
            s[i] = mp[x[i]];
        }
        cout << s << endl;
    }

    return 0;
}
