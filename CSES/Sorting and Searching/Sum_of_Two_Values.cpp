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
    int i = 0, j = n - 1;
    while (i < j)
    {
        ll sum = v[i].first + v[j].first;
        if (sum == x)
        {
            cout << v[j].second << " " << v[i].second << endl;
            return 0;
        }
        else if (sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
