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

void solve()
{
    ll n;
    cin >> n;
    ll a[3][n];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    ll s = accumulate(a[0], a[0] + n, 0LL);
    s = (s + 2) / 3;
    vector<int> v = {0, 1, 2};
    do
    {
        ll k = 0, x = 0;
        while (k < n)
        {
            x += a[v[0]][k];
            if (x >= s)
                break;
            k++;
        }
        k++;
        int a1 = k;
        x = 0;
        while (k < n)
        {
            x += a[v[1]][k];
            if (x >= s)
                break;
            k++;
        }
        k++;
        int a2 = k;
        x = 0;
        while (k < n)
        {
            x += a[v[2]][k];
            if (x >= s)
                break;
            k++;
        }
        int a3 = k + 1;
        // cout << a1 << " " << a2 << " " << a3 << endl;
        if (k >= n)
        {
            continue;
        }
        else
        {
            vector<pair<int, int>> ans(3);
            ans[v[0]] = {1, a1};
            ans[v[1]] = {a1 + 1, a2};
            ans[v[2]] = {a2 + 1, a3};
            for (auto [u, v] : ans)
                cout << u << " " << v << " ";
            ln;
            return;
        }
    } while (next_permutation(all(v)));
    cout << "-1\n";
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