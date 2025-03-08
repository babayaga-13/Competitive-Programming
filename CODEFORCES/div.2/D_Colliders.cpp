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

const int MOD = 1e9 + 7;
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
            ans = ((__int128_t)ans * a) % MOD, n--;
        a = ((__int128_t)a * a) % MOD, n /= 2;
    }
    return ans;
}
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int n, m;
int curr[100000 + 7] = {0};
int d[100000 + 7] = {0};
int check(int y)
{
    for (int i = 2; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            if (d[i])
            {
                return d[i];
            }
            while (y % i == 0)
                y /= i;
        }
    }
    if (y > 1 && d[y])
        return d[y];
    return 0;
}
void insert(int x)
{
    int xx = x;
    for (int i = 2; i * i <= xx; i++)
    {
        if (xx % i == 0)
        {
            d[i] = x;
            while (xx % i == 0)
            {
                xx /= i;
            }
        }
    }
    if (xx > 1)
        d[xx] = x;
}
void remove(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            d[i] = 0;
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x > 1)
        d[x] = 0;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    while (m--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            if (curr[x])
            {
                cout << "Already on\n";
            }
            else
            {
                int z = check(x);
                if (z == 0)
                {
                    cout << "Success\n";
                    insert(x);
                    curr[x] = 1;
                }
                else
                {
                    cout << "Conflict with " << z << endl;
                }
            }
        }
        else
        {
            if (curr[x] == 0)
            {
                cout << "Already off\n";
            }
            else
            {
                cout << "Success\n";
                curr[x] = 0;
                remove(x);
            }
        }
    }
    return 0;
}