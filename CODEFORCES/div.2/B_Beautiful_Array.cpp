#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
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
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        if (s < k * b || (b * k + (n * (k - 1))) < s)
            cout << "-1\n";
        else
        {
            vector<ll> v;
            s -= (b * k);
            ll x = b * k;
            k--;
            x += min(s, k);
            s -= min(s, k);
            v.push_back(x);

            while (n > 1)
            {
                v.push_back(min(k, s));
                s -= min(k, s);
                n--;
            }
            for (auto u : v)
                cout << u << " ";
            ln;
        }
    }
    return 0;
}
