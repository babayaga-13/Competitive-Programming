#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
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
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = (ans * a) % N, n--;
        else
            a = (a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    ll n, k, c = 0;
    cin >> n >> k;
    vector<ll> a(n), b(n), d(n), x(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
            c++;
    }

    if (c > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (b[i] == 1)
            {
                a[i] += (k / c);
            }
        }
        k = k % c;

        for (int i = 0; i < n; i++)
        {
            if (b[i] == 1 && k > 0)
            {
                a[i]++;
                k--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        d[i] = a[i];
    }

    sort(all(d));
    ll mid = n / 2;
    for (int i = 0; i < n; i++)
    {
        {
            if (a[i] < d[mid])
                x[i] = d[mid];
            else
                x[i] = d[mid - 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] + x[i]);
    }
    cout << ans << endl;
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
