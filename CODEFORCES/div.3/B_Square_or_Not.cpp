#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define count_one(x) __builtin_popcount(x)
#define trailing_zero(x) __builtin_ctz(x)
#define leading_zero(x) __builtin_clz(x)
#define gcd __gcd
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k = sqrt(n);
    if (k * k != n)
    {
        no;
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (s[i] != '1' || s[n - 1 - i] != '1')
        {
            no;
            return;
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (s[i * k] != '1' || s[(i + 1) * k - 1] != '1')
        {
            no;
            return;
        }
    }

    for (int i = 1; i < k - 1; i++)
    {
        for (int j = 1; j < k - 1; j++)
        {
            if (s[i * k + j] != '0')
            {
                no;
                return;
            }
        }
    }
    yes;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
