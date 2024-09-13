#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int sum = 0;
        int c = 1;
        cin >> s;
        for (int i = 0; i < 4; i++)
        {
            int x = s[i] - 48;
            if (x == 0)
                x = 10;
            sum += (abs(c - x) + 1);
            c = x;
        }
        cout << sum << endl;
    }
}
