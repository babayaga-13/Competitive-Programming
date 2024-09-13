#include <bits/stdc++.h>
#define ll long long
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
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i < n; i++)
            a[i] += a[i - 1];
        while (q--)
        {
            int l, r, k, sum;
            cin >> l >> r >> k;
            if (l == 1)
                sum = (r - l + 1) * k + (a[n - 1] - a[r - 1]);
            else
                sum = a[l - 2] + (r - l + 1) * k + (a[n - 1] - a[r - 1]);
            if (sum % 2 != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
