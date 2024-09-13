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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (k >= 3)
        {
            cout << 0 << endl;
            continue;
        }
        sort(begin(a), end(a));
        ll d = a[0];
        for (int i = 0; i < n - 1; i++)
            d = min(d, a[i + 1] - a[i]);
        if (k == 1)
        {
            cout << d << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                ll v = a[i] - a[j];
                ll p = lower_bound(begin(a), end(a), v) - begin(a);
                if (p < n)
                    d = min(d, a[p] - v);
                if (p > 0)
                    d = min(d, v - a[p - 1]);
            }
        cout << d << endl;
    }
}