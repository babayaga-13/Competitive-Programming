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
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> l(m + 1), r(m + 1);
    vector<ll> d(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i] >> d[i];

    vector<ll> op(m + 2, 0);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        op[x]++;
        op[y + 1]--;
    }
    for (int i = 1; i <= m; i++)
        op[i] += op[i - 1];

    vector<ll> add(n + 2, 0);
    for (int i = 1; i <= m; i++)
    {
        add[l[i]] += d[i] * op[i];
        add[r[i] + 1] -= d[i] * op[i];
    }

    for (int i = 1; i <= n; i++)
    {
        add[i] += add[i - 1];
        a[i] += add[i];
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
