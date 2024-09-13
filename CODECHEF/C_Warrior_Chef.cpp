#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool check(int a[], int n, int x, int H)
{
    for (int i = 0; i < n; i++)
    {
        if (x >= a[i])
            continue;
        else if (H > a[i])
            H -= a[i];
        else
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, H;
        cin >> n >> H;
        int a[n], s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        int l = 0, h = s, ans = INT_MAX;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (check(a, n, m, H))
            {
                ans = m;
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << ans << endl;
    }
}