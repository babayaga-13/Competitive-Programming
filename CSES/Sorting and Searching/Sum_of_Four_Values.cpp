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
    int i, j;
    for (i = 0; i < n - 3; i++)
    {
        for (j = i + 1; j < n - 2; j++)
        {
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                ll sum = v[i].first + v[j].first + v[k].first + v[l].first;
                if (sum == x)
                {
                    cout << v[i].second << " " << v[j].second << " " << v[k].second << " " << v[l].second << endl;
                    return 0;
                }
                else if (sum < x)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
