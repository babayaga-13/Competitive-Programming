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
vector<string> v;
const ll N = (ll)2e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (ll p2 = 1; p2 <= N; p2 *= 2)
        v.push_back(to_string(p2));
    int t = 1;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        int ans = n.length() + 1;
        for (auto u : v)
        {
            int i = 0, j = 0, c = 0;
            int a = n.size(), b = u.size();

            while (i < n.size() && j < u.size())
            {
                if (n[i] == u[j])
                {
                    j++;
                    c++;
                }
                i++;
            }

            ans = min(ans, (a - c + b - c));
        }
        cout << ans << endl;
    }
    return 0;
}