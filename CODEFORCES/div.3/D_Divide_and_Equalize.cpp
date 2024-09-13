#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
void solve(map<int, int> &mp, int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                mp[i]++;
                x /= i;
            }
        }
    }
    if (x > 1)
        mp[x]++;
}
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
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            solve(mp, x);
        }
        string ans = "YES\n";
        for (auto u : mp)
        {
            if (u.second % n != 0)
            {
                ans = "NO\n";
                break;
            }
        }
        cout << ans;
    }
}