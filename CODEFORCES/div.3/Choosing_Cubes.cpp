#include <bits/stdc++.h>
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define maybe cout << "MAYBE" << endl

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
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int favorite_value = a[f - 1];
        sort(a.rbegin(), a.rend());

        int p1 = lower_bound(a.begin(), a.end(), favorite_value, greater<int>()) - a.begin();
        int p2 = upper_bound(a.begin(), a.end(), favorite_value, greater<int>()) - a.begin();

        if (p2 <= k)
        {
            yes;
        }
        else if (p1 >= k)
        {
            no;
        }
        else
        {
            maybe;
        }
    }

    return 0;
}
