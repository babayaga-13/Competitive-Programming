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
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n == 1)
        {
            cout << "0\n";
            continue;
        }

        int c = 0, f = 0;
        for (int i = 1; i < n; i++)
        {
            if (f % 2 != 0)
            {
                if (s[i] == '1')
                    s[i] = '0';
                else
                    s[i] = '1';
            }
            if (s[i] == s[i - 1])
            {
                f++;
                if (s[i] == '1')
                    s[i] = '0';
                else
                    s[i] = '1';
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}
