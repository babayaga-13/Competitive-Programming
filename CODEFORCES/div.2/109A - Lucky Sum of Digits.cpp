#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    while (n != 0)
    {
        if (n % 7 == 0)
        {
            v.push_back(7);
            n -= 7;
        }
        else if (n % 4 == 0)
        {
            v.push_back(4);
            n -= 4;
        }

        else if (n > 4)
        {
            n -= 4;
            v.push_back(4);
        }
        else
        {
            cout << "-1";
            return 0;
        }
    }
    for (auto u : v)
        cout << u;
    return 0;
}
