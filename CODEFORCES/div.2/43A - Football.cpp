#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s, d;
    cin >> s;
    t--;
    int a = 1, b = 0;
    while (t--)
    {
        string c;
        cin >> c;
        if (c != s)
        {
            b++;
            d = c;
        }
        else
            a++;
    }
    if (a > b)
        cout << s;
    else
        cout << d;
}
