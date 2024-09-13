#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 0;
        char k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<char> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] < k)
            {
                if (c == 0)
                {
                    v.push_back(k);
                    v.push_back(s[i]);
                    c++;
                }
                else
                v.push_back(s[i]);
            }
            else
                v.push_back(s[i]);
        }
        if (c == 0)
            v.push_back(k);
        for (int i = 0; i <= n; i++)
            cout << v[i];
        cout << endl;
    }
}
