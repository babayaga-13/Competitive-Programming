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
        int n, f = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n)
            {
                if (s[i] == s[j])
                {
                    f++;
                    break;
                }
                j += 2;
            }
        }
        if (f == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
