#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        vector<pair<ll, ll>> v;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, 1});
            v.push_back({y + 1, -1});
        }

        sort(v.begin(), v.end());

        ll sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i].second;
            if (sum > 2)
            {
                no;
                return 0;
            }
        }
        yes;
    }
    return 0;
}
