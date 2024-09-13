#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n;

void check(ll x)
{
    if (x > n)
        return;
    while (n % x == 0 && x != 1)
    {
        n /= x;
    }

    check(x * 10);
    check(x * 10 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {

        cin >> n;
        check(1);
        if (n == 1)
            yes;
        else
            no;
    }
    return 0;
}
