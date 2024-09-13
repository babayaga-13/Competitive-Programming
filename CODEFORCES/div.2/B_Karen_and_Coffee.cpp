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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n, k, q;
        cin >> n >> k >> q;
        const ll N = 200000;
        vector<ll> a(N + 2, 0);

        for (ll i = 0; i < n; ++i)
        {
            ll l, r;
            cin >> l >> r;
            a[l]++;
            a[r + 1]--;
        }

        for (ll i = 1; i <= N; ++i)
            a[i] += a[i - 1];

        for (ll i = 1; i <= N; ++i)
        {
            if (a[i] >= k)
                a[i] = 1;
            else
                a[i] = 0;
        }
        vector<ll> count(N + 1, 0);
        for (ll i = 1; i <= N; ++i)
            count[i] = count[i - 1] + a[i];

        for (ll i = 0; i < q; ++i)
        {
            ll a, b;
            cin >> a >> b;
            ll ans = count[b] - count[a - 1];
            cout << ans << endl;
        }
    }

    return 0;
}
