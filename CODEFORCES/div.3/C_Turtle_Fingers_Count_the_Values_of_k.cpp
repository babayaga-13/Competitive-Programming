#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, l;
        cin >> a >> b >> l;
        vector<int> d;
        for (int i = 1; i * i <= l; i++)
        {
            if (l % i == 0)
            {
                d.push_back(i);
                if (l % (l / i) == 0 && i != (l / i))
                {
                    d.push_back(l / i);
                }
            }
        }

        sort(d.begin(), d.end());
        ll c = 0;
        for (int i = 0; i < d.size(); i++)
        {
            int x = l / d[i];
            if (x % a == 0)
                c++;
            if (x % b == 0)
                c++;
        }
        cout << c << endl;
    }
    return 0;
}
