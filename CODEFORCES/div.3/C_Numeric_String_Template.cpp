#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#define all(v) v.begin(), v.end()
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
            ans = (ans * a) % N, n--;
        else
            a = (a * a) % N, n /= 2;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        int x = s.size();
        bool f = true;
        if (x != n)
        {
            no;
            continue;
        }
        map<int, char> m1;
        map<char, int> m2;
        for (int i = 0; i < n; i++)
        {
            int ai = a[i];
            char si = s[i];
            if (m1.count(ai) == 0)
            {
                m1[ai] = si;
            }
            else if (m1[ai] != si)
            {
                f = false;
                break;
            }
            if (m2.count(si) == 0)
            {
                m2[si] = ai;
            }
            else if (m2[si] != ai)
            {
                f = false;
                break;
            }
        }
        if (f)
            yes;
        else
            no;
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