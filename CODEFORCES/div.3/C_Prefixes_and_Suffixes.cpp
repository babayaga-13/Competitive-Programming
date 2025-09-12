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

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

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
    int n;
    cin >> n;

    vector<string> s(2 * n);
    vector<int> used(n + 1, 0);
    string max1 = "", max2 = "", pr;

    for (int i = 1; i <= 2 * n - 2; i++)
    {
        cin >> s[i];
        if (s[i].size() == n - 1)
        {
            if (max1.empty())
                max1 = s[i];
            else
                max2 = s[i];
        }
    }

    int f = 0;
    for (int i = 1; i <= 2 * n - 2; i++)
    {
        if (max1.substr(0, s[i].size()) == s[i])
            f++;
    }

    if (f >= (2 * n - 2) / 2 && max1.substr(1, n - 2) == max2.substr(0, n - 2))
        pr = max1;
    else
        pr = max2;

    for (int i = 1; i <= 2 * n - 2; i++)
    {
        if (s[i] == pr.substr(0, s[i].size()) && !used[s[i].size()])
        {
            used[s[i].size()] = 1;
            cout << "P";
        }
        else
            cout << "S";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
