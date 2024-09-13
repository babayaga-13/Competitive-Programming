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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        map<vector<int>, int> mp1, mp2;
        ll ans = 0;

        for (int i = 0; i < n - 2; i++)
        {
            vector<int> triplet = {v[i], v[i + 1], v[i + 2]};
            vector<int> v1 = {0, v[i + 1], v[i + 2]};
            vector<int> v2 = {v[i], 0, v[i + 2]};
            vector<int> v3 = {v[i], v[i + 1], 0};

            ans += mp1[v1] - mp2[triplet];
            ans += mp1[v2] - mp2[triplet];
            ans += mp1[v3] - mp2[triplet];

            mp1[v1]++;
            mp1[v2]++;
            mp1[v3]++;
            mp2[triplet]++;
        }

        cout << ans << endl;
    }

    return 0;
}
