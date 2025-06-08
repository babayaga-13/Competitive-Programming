#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pi <int,int>
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define count_one(x) __builtin_popcountll(x)
#define trailing_zero(x) __builtin_ctzll(x)
#define leading_zero(x) __builtin_clzll(x)
#define gcd __gcd
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

ll power_ll(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n % 2)
        {
            if (__builtin_mul_overflow(ans, a, &ans))
                return LLONG_MAX;
            n--;
        }
        if (__builtin_mul_overflow(a, a, &a))
            return LLONG_MAX;
        n /= 2;
    }
    return ans;
}


void solve()
{
    int n;
    cin >> n;
    if ((n & (n - 1)) == 0)
    {
        cout << "-1\n"; 
    }
    else
    {
        int x = trailing_zero(n);
        int div = n >> x;
        cout << min(power_ll(2, x + 1), div) << endl;
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
