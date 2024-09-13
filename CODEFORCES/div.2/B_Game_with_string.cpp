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
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int ans = 0;
        for (char ch : s)
        {
            if (!st.empty() && st.top() == ch)
            {
                ans++;
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        if (ans % 2)
            yes;
        else
            no;
    }
    return 0;
}
