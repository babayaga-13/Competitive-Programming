#include <bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;

ll fl[N], fr[N], tl[N], tr[N];
char s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, Q;
        cin >> n >> m >> Q;
        cin >> (s + 1);

        tl[0] = 1;
        tr[0] = n;

        for (int i = 1; i <= m; i++)
        {
            cin >> fl[i] >> fr[i];
            tl[i] = tr[i - 1] + 1;
            tr[i] = tl[i] + (fr[i] - fl[i] + 1) - 1;
        }

        while (Q--)
        {
            ll x;
            cin >> x;
            int u = -1;

            while (true)
            {
                for (int i = 0; i <= m; ++i)
                {
                    if (tl[i] <= x && tr[i] >= x)
                    {
                        u = i;
                        break;
                    }
                }
                if (u == 0)
                    break;
                x = fl[u] + (x - tl[u]);
            }

            cout << s[x] << '\n';
        }
    }

    return 0;
}
