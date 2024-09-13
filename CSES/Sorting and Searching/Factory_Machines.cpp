#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll l = 0, h = 1e18, ans = 0;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            s += (mid / a[i]);
            if (s >= t)
                break;
        }
        if (s >= t)
        {
            ans = mid;
            h = mid - 1;
        }

        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}
