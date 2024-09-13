#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, -y});
    }
    sort(v.rbegin(), v.rend());
    ll ans = 1;
    ll i = k - 1;
    while (i < n - 1)
    {
        if (v[i].first == v[i + 1].first && v[i].second == v[i + 1].second)
            ans++;
        else
            break;
        i++;
    }
    i = k - 1;
    while (i > 0)
    {
        if (v[i].first == v[i - 1].first && v[i].second == v[i - 1].second)
            ans++;
        else
            break;
        i--;
    }
    cout << ans;
}