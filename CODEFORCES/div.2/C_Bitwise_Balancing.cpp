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
    long long b, c, d;
    cin >> b >> c >> d;
    long long a = 0;
    for (int bit = 0; bit <= 61; bit++)
    {
        int b_bit = (b >> bit) & 1;
        int c_bit = (c >> bit) & 1;
        int d_bit = (d >> bit) & 1;

        if (d_bit == 0)
        {
            if (b_bit == 0 && c_bit == 1)
            {
                a |= (1LL << bit);
            }
            else if (b_bit == 1 && c_bit == 1)
            {
                a |= (1LL << bit);
            }
            else if (b_bit == 1 && c_bit == 0)
            {
                cout << "-1\n";
                return;
            }
        }
        else
        {
            if (b_bit == 0 && c_bit == 0)
                a |= (1LL << bit);
            else if (b_bit == 1 && c_bit == 0)
                a |= (1LL << bit);
            else if (b_bit == 0 && c_bit == 1)
            {
                cout << "-1\n";
                return;
            }
        }
    }

    {
        cout << a << '\n';
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