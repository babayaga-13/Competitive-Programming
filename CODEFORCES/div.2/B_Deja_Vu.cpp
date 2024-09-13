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
        int n, q;
        cin >> n >> q;
        vector<ll> v(n);
        vector<int> f(31, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        while (q--)
        {
            int x;
            cin >> x;
            if (f[x] == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (v[i] % (1 << x) == 0)
                    {
                        int y = x - 1;
                        v[i] += (1 << (y));
                    }
                }
                f[x] = 1;
            }
        }
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }
}