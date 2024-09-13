#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<ll, ll> mp;
    ll sum = 0;
    ll ans = 0;
    mp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (mp.find(sum - x) != mp.end())
        {
            ans += mp[sum - x];
        }
        mp[sum]++;
    }

    cout << ans << endl;

    return 0;
}
