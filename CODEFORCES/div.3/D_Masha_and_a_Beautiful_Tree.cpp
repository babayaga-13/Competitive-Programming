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
const int MAXM = 300300;

int n, m;
int arr[MAXM];
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

int solve(int l, int r)
{
    if (r - l == 1)
        return 0;
    int mid = (l + r) / 2;
    int mal = *max_element(arr + l, arr + mid);
    int mar = *max_element(arr + mid, arr + r);
    int ans = 0;
    if (mal > mar)
    {
        ans++;
        for (int i = 0; i < (mid - l); ++i)
            swap(arr[l + i], arr[mid + i]);
    }
    return solve(l, mid) + solve(mid, r) + ans;
}

int solve()
{
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> arr[i];
    int ans = solve(0, m);
    if (is_sorted(arr, arr + m))
        return ans;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
}