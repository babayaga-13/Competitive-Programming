#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    ll sum = 0;
    int m = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 != 0)
        {
            m = min(m, a[i]);
        }
    }
    if (sum % 2 == 0)
        cout << sum;
    else
        cout << sum - m;
    return 0;
}
