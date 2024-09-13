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
        ll x;
        cin >> x;
        ll cnt = 0;
        if (x % 2 == 1)
            cout << "1" << endl;
        else
        {
            for (int i = 1; i < 1000; i++)
            {
                if (x % i == 0)
                    cnt++;
                else
                    break;
            }
            cout << cnt << endl;
        }
    }
}