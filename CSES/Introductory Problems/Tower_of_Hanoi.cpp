#include <bits/stdc++.h>
using namespace std;
vector<pair<char, char>> v;
int ans = 0;
void towerOfHanoi(int n, char x, char z, char y)
{
    if (n == 1)
    {
        v.push_back({x, z});
        ans++;
        return;
    }
    towerOfHanoi(n - 1, x, y, z);
    v.push_back({x, z});
    ans++;
    towerOfHanoi(n - 1, y, z, x);
}

void solve()
{
    int N;
    cin >> N;
    towerOfHanoi(N, '1', '3', '2');
    cout << ans << endl;
    for (const auto &u : v)
        cout << u.first << " " << u.second << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t; // Uncomment if you want to handle multiple test cases
    while (t--)
    {
        solve();
    }
    return 0;
}
