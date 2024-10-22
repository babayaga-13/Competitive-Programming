#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;

bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    if (max(a.first, a.second) == max(b.first, b.second))
    {
        return min(a.first, a.second) < min(b.first, b.second);
    }
    return max(a.first, a.second) < max(b.first, b.second);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(all(v), customComparator);
    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << " ";
    ln;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
