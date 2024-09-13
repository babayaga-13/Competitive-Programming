#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl

using namespace std;

void solve()
{
    ll n;
    cin >> n;

    // Calculate the sum of the first n natural numbers
    ll x = (n * (n + 1)) / 2;

    // If the sum is odd, it's not possible to divide it into two equal subsets
    if (x % 2)
    {
        no;
        return;
    }

    x /= 2; // We need to find a subset with sum x
    set<ll> a, b;

    // Partition the numbers into two sets
    for (int i = n; i > 0; i--)
    {
        if (i <= x)
        {
            a.insert(i);
            x -= i;
        }
        else
        {
            b.insert(i);
        }
    }

    // Output the results
    yes;
    cout << a.size() << endl;
    for (auto u : a)
        cout << u << " ";
    ln;

    cout << b.size() << endl;
    for (auto u : b)
        cout << u << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
