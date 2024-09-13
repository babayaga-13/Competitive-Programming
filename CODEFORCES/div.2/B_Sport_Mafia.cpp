#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int l = 0, h = n + 1, ans = 0;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        ll x = n - m;
        if (x * (x + 1) / 2 >= (k + m))
        {
            ans = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }
    cout << ans << endl;
}