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
        int n = s.size();
        int x = s[0] - '0';
        int ans = (x - 1) * 10;
        if (n == 1)
            ans += 1;
        else if (n == 2)
            ans += 3;
        else if (n == 3)
            ans += 6;
        else
            ans += 10;

        cout << ans << endl;
    }
}
