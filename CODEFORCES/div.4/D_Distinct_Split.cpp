#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ln cout << endl
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // set<char> st;
        // ll a[n], b[n];
        // for (int i = 0; i < n; i++)
        // {
        //     st.insert(s[i]);
        //     a[i] = st.size();
        // }
        // st.clear();
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     st.insert(s[i]);
        //     b[i] = st.size();
        // }
        // ll ans = 0;
        // for (int i = 0; i < n - 1; i++)
        // {
        //     ans = max(ans, a[i] + b[i + 1]);
        // }
        // cout << ans << endl;

        set<char> st;
        map<ll, ll> mp, m;
        st.insert(s.begin(), s.end());
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        ll ans = 0;
        ll c = 0;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            if (mp[s[i]] > 1)
            {
                if (m[s[i]] == 1)
                    c++;
                else if (m[s[i]] == mp[s[i]])
                    c--;
                ans = max(ans, c);
            }
        }
        cout << ans + st.size() << endl;
    }
    return 0;
}
