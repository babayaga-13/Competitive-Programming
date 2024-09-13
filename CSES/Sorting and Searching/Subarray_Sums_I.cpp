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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll i = 0, j = 0, sum = 0, ans = 0;
    while (i < n)
    {
        sum += v[i];

        while (sum > x && j <= i)
        {
            sum -= v[j];
            j++;
        }

        if (sum == x)
        {
            ans++;
        }

        i++;
    }

    cout << ans << endl;

    return 0;
}
