#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
                st.push(s[i]);
            else if (!st.empty() && st.top() == '1')
                st.push(s[i]);
        }
        ll x = 0, y = 0;
        while (!st.empty())
        {
            if (st.top() == '1')
                x++;
            else
                y++;
            st.pop();
        }
        if (x > y)
            yes;
        else
            no;
    }
    return 0;
}
