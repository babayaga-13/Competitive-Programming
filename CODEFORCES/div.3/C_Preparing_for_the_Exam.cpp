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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m), b(k);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    string s;
    set<ll> st;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }

    if (n > k + 1)
    {
        for (int i = 0; i < m; i++)
            cout << "0";
        ln;
        return;
    }
    if (n == k)
    {
        for (int i = 0; i < m; i++)
            cout << "1";
        ln;
        return;
    }

    for (int i = 0; i < m; i++)
        s += (st.count(a[i]) ? '0' : '1');

    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
