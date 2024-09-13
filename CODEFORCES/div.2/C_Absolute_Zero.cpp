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
    int n, c = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
            c++;
    }
    if (c > 0 && c < n)
    {
        cout << "-1\n";
        return;
    }

    // sort(a, a + n);
    // vector<int> v;
    // for (;;)
    // {
    //     if (a[0] == 0 && a[n - 1] == 0)
    //     {
    //         cout << v.size() << endl;
    //         for (auto u : v)
    //             cout << u << " ";
    //         ln;
    //         return;
    //     }
    //     int x = a[0] + a[n - 1];
    //     x /= 2;
    //     for (int i = 0; i < n; i++)
    //     {
    //         a[i] = abs(a[i] - x);
    //     }
    //     v.push_back(x);
    //     sort(a, a + n);
    //     }

    cout << 32 << '\n';
    cout << a[0];
    for (int i = 29; i >= 0; i--)
    {
        cout << " " << (1 << i);
    }
    cout << " " << 1 << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}