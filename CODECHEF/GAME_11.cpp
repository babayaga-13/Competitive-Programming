#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        if (n < 4 || m < 4)
        {
            cout << "-1\n";
            continue;
        }
        ll ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans += a[i];
            ans += b[i];
        }
        int count = 8, i = 4, j = 4;
        while ((i < n || j < m) && count < 11)
        {
            if (i < n && j < m)
            {
                if (a[i] > b[j])
                {
                    ans += a[i];
                    i++;
                    count++;
                }
                else
                {
                    ans += b[j];
                    j++;
                    count++;
                }
            }
            else if (i == n)
            {
                ans += b[j];
                j++;
                count++;
            }
            else if (j == m)
            {
                ans += a[i];
                i++;
                count++;
            }
        }
        cout << ans << endl;
    }
}