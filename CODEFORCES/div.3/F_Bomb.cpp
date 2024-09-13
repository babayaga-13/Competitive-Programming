#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
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
        int n, k;
        cin >> n >> k;
        ll a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int l = 0, r = 1e9, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            ll c = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] >= mid)
                {
                    c += (a[i] - mid) / b[i] + 1;
                }
            }
            if (c >= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        ll sum = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= ans)
            {
                ll c = (a[i] - ans) / b[i] + 1;
                cnt += c;
                sum += a[i] * c;
                sum -= c * b[i] * (c - 1) / 2;
            }
        }
        sum -= (cnt - k) * ans;
        cout << sum << endl;
    }

    return 0;
}
