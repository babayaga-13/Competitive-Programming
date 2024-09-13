#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        ll ans = 0;
        for (int x : {1, 2, 3})
        {
            int bad = x - 1;
            if (bad == 0)
                bad = 3;

            int L = n, R = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == x)
                {
                    L = min(i, L);
                    R = i;
                }
            }

            int L2 = L, R2 = R, good = 1;
            for (int i = L; i <= R; i++)
            {
                if (a[i] == bad)
                    good = 0;
            }

            while (L2 >= 0)
            {
                if (a[L2] == bad)
                    break;
                --L2;
            }
            while (R2 < n)
            {
                if (a[R2] == bad)
                    break;
                ++R2;
            }

            ans += 1ll * good * (R2 - R) * (L - L2);
        }
        cout << 1ll * n * (n + 1) / 2 - ans << '\n';
    }
}