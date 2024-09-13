#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n - 1);
    for (ll i = 0; i < n - 1; ++i)
        cin >> a[i];

    long long k = n * (n + 1) / 2;

    if (a[n - 2] > k)
    {
        cout << "NO\n";
        return;
    }

    a.insert(a.begin(), 0);

    vector<long long> v;
    for (ll i = 1; i < n; ++i)
    {
        v.push_back(a[i] - a[i - 1]);
    }

    set<ll> st;
    for (ll i = 1; i <= n; ++i)
    {
        st.insert(i);
    }

    ll duplicate = -1;
    for (ll i = 0; i < v.size(); ++i)
    {
        if (v[i] <= n && st.count(v[i]))
        {
            st.erase(v[i]);
        }
        else
        {
            if (duplicate != -1)
            {
                cout << "NO\n";
                return;
            }
            duplicate = v[i];
        }
    }

    if (duplicate == -1)
    {
        cout << "YES\n";
        return;
    }

    for (ll missing : st)
    {
        duplicate -= missing;
    }

    if (duplicate == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
