#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int ans = 0, s = 0;
        int i = 0, j = 0;

        while (i < n)
        {
            s += a[i];
            while (s > r && j < n)
            {
                s -= a[j];
                j++;
            }
            if (s >= l && s <= r)
            {
                ans++;
                s = 0;
                j = i + 1;
            }
            i++;
        }

        cout << ans << endl;
    }
    return 0;
}
