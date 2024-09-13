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
        int f = 1;
        vector<int> v;
        for (int i = 0; i < n - 1; i += 2)
        {
            if (s[i] != s[i + 1])
            {
                if (f != (s[i] - '0'))
                {
                    v.push_back(i + 1);
                    f = (s[i] - '0');
                }
                else
                {
                    v.push_back(i + 2);
                    f = (s[i + 1] - '0');
                }
            }
        }
        if (v.empty())
            cout << "0";
        else
        {
            cout << v.size() << endl;
            for (auto u : v)
                cout << u << " ";
        }
        cout << "\n";
    }
}