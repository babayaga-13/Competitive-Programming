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
const int N = 1e6 + 7;
int prime[N] = {0};
vector<int> primes;
void sieve()
{
    for (int i = 4; i < N; i += 2)
        prime[i] = 1;
    for (int i = 3; i * i < N; i += 2)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j < N; j += i + i)
            {
                prime[j] = i;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (!prime[i])
            primes.push_back(i);
    }
}

void solve()
{
    ll n;
    cin >> n;
    auto it = upper_bound(all(primes), (2 * n / 3));
    if (it != primes.begin())
    {
        it--;
    }
    if (n == 2)
    {
        cout << "2 1\n";
        return;
    }
    ll x = *it;
    cout << x << " ";
    ll s = x, y = 1;
    ll l = x - 1, r = x + 1;
    for (int i = 1; i < n; i += 2)
    {
        // s += l;
        // y++;
        // cout << (s + y - 1) / y << endl;
        cout << l << " ";
        // s += r;
        // y++;
        // cout << (s + y - 1) / y << endl;
        cout << r << " ";
        l--;
        r++;
        if (l < 1 || r > n)
            break;
    }

    for (int i = l; i >= 1; i--)
    {
        cout << i << " ";
    }
    for (int i = r; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}