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
        ll n;
        cin >> n;
        vector<ll> ans;
        ans.push_back(n);
        for (int i = 0; i < 62; i++)
        {
            if (n & (1LL << i))
            {
                ll x = n - (1LL << i);
                if (x > 0)
                    ans.push_back(x);
            }
        }
        ll y = ans.size();
        cout << y << endl;
        for (ll i = y - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        ln;
    }
    return 0;
}
