#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
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
        int n, k;
        cin >> n >> k;
        vector<string> v(n);
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            int c = 0, l = 0;
            for (int j = 0; j < k; j++)
            {
                if (v[i][j] == '1')
                {
                    c++;
                    l = j;
                }
            }

            if (c == 1)
            {
                s.insert(l);
            }
        }

        if (s.size() == k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}