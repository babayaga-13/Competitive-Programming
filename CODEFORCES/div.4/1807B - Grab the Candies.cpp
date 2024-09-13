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
        int m = 0, b = 0;
        while (n--)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                m += x;
            else
                b += x;
        }
        if (m > b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
