
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        ll sum = 0;
        for (ll i = 1; i <= n; i++)
        {
            sum += abs((n - i + 1) - i);
            v.push_back(i);
        }
        if (k % 2 == 1 || sum < k)
        {
            no;
            continue;
        }
        yes;
        ll x = 0;
        ll y = n;
        while (k > (y - 1) * 2)
        {

            k -= (y - 1) * 2;
            y -= 2;
            swap(v[x], v[n - x - 1]);
            x++;
        }
        k /= 2;
        swap(v[x], v[x + k]);
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
