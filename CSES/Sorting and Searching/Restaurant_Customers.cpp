#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());
    ll ans = 0, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i].second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}