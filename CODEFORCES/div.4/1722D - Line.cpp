#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long c = 0;
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                v.push_back(i - (n - 1 - i));
                c += i;
            }
            else if (s[i] == 'R')
            {
                v.push_back((n - 1 - i) - i);
                c += (n - 1 - i);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (v[i] < 0)
            {
                c -= v[i];
            }
            cout << c << " ";
        }
        cout << endl;
    }
}
