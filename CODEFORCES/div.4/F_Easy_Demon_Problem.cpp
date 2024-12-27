#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    ll total_a = accumulate(a.begin(), a.end(), 0LL);
    ll total_b = accumulate(b.begin(), b.end(), 0LL);

    ll S = total_a * total_b; // Initial grid beauty

    map<ll, ll> row_sum, col_sum;
    for (int i = 0; i < n; i++)
        row_sum[a[i] * total_b]++;
    for (int j = 0; j < m; j++)
        col_sum[b[j] * total_a]++;

    while (q--)
    {
        ll x;
        cin >> x;

        bool possible = false;
        for (auto [key, freq] : row_sum)
        {
            ll remaining = x - (S - key);
            if (col_sum.count(remaining))
            {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
