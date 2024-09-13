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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;

        pair<ll, ll> p;
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            vector<int> a(m);
            for (int j = 0; j < m; j++)
                cin >> a[j];

            sort(a.begin(), a.end());
            for (int j = 1; j < m; j++)
                a[j] += a[j - 1];

            ll c = 0, penalty = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[j] > h)
                    break;
                penalty += a[j];
                c++;
            }

            if (i == 0)
                p = {c, -penalty};
            else if (make_pair(c, -penalty) > p)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
