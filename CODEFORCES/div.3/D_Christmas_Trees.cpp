#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vpi vector<pi>
#define vii vector<vector<int>>
#define pi pair<int, int>
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
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
ll power(ll a, ll n)
{
    ll cnt = 1;
    while (n)
    {
        if (n % 2)
            cnt = ((__int128_t)cnt * a) % MOD, n--;
        a = ((__int128_t)a * a) % MOD, n /= 2;
    }
    return cnt;
}
int phi(int n)
{
    int ansult = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            ansult -= ansult / i;
        }
    }
    if (n > 1)
        ansult -= ansult / n;
    return ansult;
}
long long fact[N], inv_fact[N];
void init_fact()
{
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[N - 1] = power(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 1; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}
int nCr(int n, int r)
{
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
long long nPr(int n, int r)
{
    return fact[n] * inv_fact[n - r] % MOD;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
        mp[x] = 0;
    }
    int cnt = 0;
    vi ans;
    while (m)
    {
        int x = q.front();
        q.pop();
        if (mp[x])
        {
            cnt += mp[x];
            ans.push_back(x);
            m--;
        }
        if (!mp.count(x - 1))
        {
            mp[x - 1] = mp[x] + 1;
            q.push(x - 1);
        }
        if (!mp.count(x + 1))
        {
            mp[x + 1] = mp[x] + 1;
            q.push(x + 1);
        }
    }
    cout << cnt << endl;
    for (auto u : ans)
        cout << u << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}