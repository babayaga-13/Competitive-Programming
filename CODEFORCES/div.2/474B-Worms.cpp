#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        v[i] = (v[i - 1] + a[i - 1]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        cout << it - v.begin() << endl;
    }
}
