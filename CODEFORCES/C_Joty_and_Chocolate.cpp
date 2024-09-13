#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    ll ans = ((n / a) * p + (n / b) * q - (n / lcm(a, b)) * min(p, q));
    cout << ans;
}