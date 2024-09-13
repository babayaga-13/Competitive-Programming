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
        int x, y, k;
        cin >> x >> y >> k;
        int s = 0;
        while (1)
        {
            if (y % k == 0 && y / k >= x)
            {
                s++;
                y = y / k;
            }
            else if (y % k == 0)
            {
                s = s + y - x;
                break;
            }
            else
            {
                s = s + y % k;
                y = y - y % k;
            }
        }
        cout << s << endl;
    }
}