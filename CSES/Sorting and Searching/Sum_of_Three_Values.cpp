#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            ll sum = v[i].first + v[j].first + v[k].first;
            if (sum == x)
            {
                cout << v[j].second << " " << v[k].second << " " << v[i].second << endl;
                return 0;
            }
            else if (sum < x)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
