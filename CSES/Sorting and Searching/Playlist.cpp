#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll ans = 0;
    ll i = 0, j = 0;
    set<int> s;

    while (i < n && j < n)
    {
        if (!s.count(v[i]))
        {
            s.insert(v[i]);
            ans = max(ans, i - j + 1);
            i++;
        }
        else if (s.count(v[i]))
        {
            s.erase(v[j]);
            j++;
        }
    }

    cout << ans << endl;
    return 0;
}
