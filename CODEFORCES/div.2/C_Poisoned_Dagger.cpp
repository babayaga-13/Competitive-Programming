#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool check(vector<ll> v, ll n, ll k, ll h)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            sum += k;
        else if (v[i] + k <= v[i + 1])
            sum += k;
        else
            sum += (v[i + 1] - v[i]);
    }
    return sum >= h;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, h;
        cin >> n >> h;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        ll lo = 0, hi = 1e18, ans = 0;
        while (lo <= hi)
        {
            ll mid = (lo + (hi - lo) / 2);
            if (check(v, n, mid, h))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
