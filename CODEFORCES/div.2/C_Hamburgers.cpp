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
using namespace std;

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
string s;
ll x, y, z, xx, yy, zz, k;
ll a = 0, b = 0, c = 0;
bool check(ll m)
{
    ll sum = 0;

    if (a)
        sum += max(0LL, (m * a) - x) * xx;
    if (sum > k)
        return false;
    sum += max(0LL, (m * b) - y) * yy;
    if (sum > k)
        return false;
    sum += max(0LL, (m * c) - z) * zz;
    return sum <= k;
}

void solve()
{
    cin >> s;
    cin >> x >> y >> z >> xx >> yy >> zz;
    cin >> k;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            a++;
        if (s[i] == 'S')
            b++;
        if (s[i] == 'C')
            c++;
    }
    ll l = 0, h = 1e15, ans = 0;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            h = mid - 1;
    }
    cout << ans << endl;
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