#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<int> v;
    if (n < 4 && n != 1)
        cout << "NO SOLUTION";
    else
    {
        for (int i = 2; i <= n; i += 2)
        {
            v.push_back(i);
        }
        for (int i = 1; i <= n; i += 2)
        {
            v.push_back(i);
        }

        for (auto u : v)
            cout << u << " ";
    }
}