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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] -= a[i];
        }
        sort(v.begin(), v.end());
        int i = 0, j = n - 1, ans = 0;
        while (i < j)
        {
            if (v[i] + v[j] >= 0)
            {
                i++;
                j--;
                ans++;
            }
            else
                i++;
        }
        cout << ans << endl;
    }
    return 0;
}
