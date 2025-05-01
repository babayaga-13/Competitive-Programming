#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y)
{
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        string ans = "A";

        int x = -1, y = -1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 1)
                x = i + 1;
            if (a[i] == n)
                y = i + 1;
        }

        if (x != -1 && y != -1)
        {
            int d1 = ask(x, y);
            int d2 = ask(y, x);
            if (d1 >= n - 1 && d1 == d2)
                ans = "B";
        }
        else
        {
            set<int> aset(a.begin(), a.end());
            for (int i = 1; i <= n; ++i)
            {
                if (aset.find(i) == aset.end())
                {
                    int d = ask(i, (i > 1 ? i - 1 : i + 1));
                    if (d)
                        ans = "B";
                    break;
                }
            }
        }

        cout << "! " << ans << endl;
    }

    return 0;
}
