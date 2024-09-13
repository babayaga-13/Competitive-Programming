#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> l(n);
        vector<int> r(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
            mp[l[i]]++;
        }
        for (int i = 0; i < n; i++)
            cin >> r[i];

        int c1 = 2 * k, c2 = k * 2;
        vector<int> ans1, ans2;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 1 && c1 > 0)
            {
                c1--;
                c2--;
                ans1.push_back(i);
                ans2.push_back(i);
            }
        }
        if (ans1.size() % 2 == 1)
        {
            ans1.pop_back();
            ans2.pop_back();
            c1++;
            c2++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 2 && c1 > 0)
            {
                c1 -= 2;
                ans1.push_back(i);
                ans1.push_back(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 0 && c2 > 0)
            {
                c2 -= 2;
                ans2.push_back(i);
                ans2.push_back(i);
            }
        }
        for (auto x : ans1)
            cout << x << " ";
        cout << endl;
        for (auto y : ans2)
            cout << y << " ";
        cout << endl;
    }
}