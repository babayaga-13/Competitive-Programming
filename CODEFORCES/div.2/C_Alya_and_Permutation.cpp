#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
            ans = ((__int128_t)ans * a) % N, n--;
        else
            a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int k = 0;
    if (n & 1)
    {
        cout << n << "\n";
        for (int i = 2; i < n - 1; i++)
            cout << i << " ";
        cout << "1 " << n - 1 << " " << n << "\n";
    }
    else
    {
        int x = count_one(n);
        if (x == 1)
        {
            int k;
            cout
                << n * 2 - 1 << "\n";
            for (int i = 2; i < n - 2; i++)
                cout << i << " ";
            cout << "1 " << n - 2 << " " << n - 1 << " " << n << "\n";
        }
        else
        {
            int y = 31 - leading_zero(n);
            cout << power(2, y + 1) - 1 << endl;
            y = power(2, y) - 1;
            for (int i = 1; i <= n; i++)
            {
                if (i != y)
                    cout << i << " ";
            }
            cout << y << endl;
        }
    }
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