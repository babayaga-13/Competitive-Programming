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
        a = ((__int128_t)a * a) % N, n /= 2;
    }
    return ans;
}
int ph(int n)
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
int x = 5e6 + 2;
vector<ll> phi(x);
void phi_1_to_n()
{
    for (int i = 0; i <= x; i++)
        phi[i] = i;

    for (int i = 2; i <= x; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= x; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
void solve()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    phi_1_to_n();
    for (int i = 1; i <= x; i++)
        phi[i] = (phi[i] * phi[i]) + phi[i - 1];
    for (int i = 0; i < t; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << "case " << i + 1 << ": " << phi[b] - phi[a - 1] << endl;
    }
    return 0;
}