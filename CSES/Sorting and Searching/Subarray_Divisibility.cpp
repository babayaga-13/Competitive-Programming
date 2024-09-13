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
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x % n);
    }
    map<int, int> mp;
    mp[0] = 1;
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        sum = (sum + n) % n;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans;
    return 0;
}
