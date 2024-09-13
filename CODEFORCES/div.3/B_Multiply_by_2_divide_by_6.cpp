#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, c = 0;
        cin >> n;
        while (n != 1)
        {
            if (n % 6 == 0)
            {
                c++;
                n /= 6;
            }
            else if (n % 3 == 0)
            {
                n *= 2;
                c++;
            }
            else
                break;
        }
        if (n == 1)
            cout << c << endl;
        else
            cout << "-1" << endl;
    }
}