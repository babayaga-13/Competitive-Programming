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
    map<int, int> mp;
    for (int j = 0; j < n; j++)
    {
        int x;
        cin >> x;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                mp[i]++;
                while (x % i == 0)
                {
                    x /= i;
                }
            }
        }
        if (x > 1)
            mp[x]++;
    }
    int ans = 1;
    for (auto u : mp)
    {
        ans = max(ans, u.second);
    }
    cout << ans;
}