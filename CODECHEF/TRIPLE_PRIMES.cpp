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

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;
vector<ll> v;
set<ll> s;
bitset<N> p;

void sieve()
{
    p.set();
    p[0] = p[1] = 0;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (p[i])
        {
            v.push_back(i * i);
            s.insert(i * i);
            for (ll j = i * i; j <= N; j += i)
                p[j] = 0;
        }
    }
    for (ll i = sqrt(N) + 1; i <= N; ++i)
    {
        if (p[i])
        {
            v.push_back(i * i);
            s.insert(i * i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    sieve();
    while (t--)
    {
        ll n, c = 1;
        cin >> n;
        for (auto u : v)
        {
            ll rem = n - 4 - u;
            if (s.count(rem) && 4 != u && u != rem && 4 != rem)
            {
                yes;
                c = 0;
                break;
            }
        }
        if (c)
            no;
    }
    return 0;
}
