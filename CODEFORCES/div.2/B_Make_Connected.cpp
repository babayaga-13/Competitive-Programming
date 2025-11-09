#include <bits/stdc++.h>
using namespace std;

int get(set<int> s)
{
    if (s.empty())
        return 0;
    return *s.rbegin() - *s.begin();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> x, y, a, b;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                char c;
                cin >> c;
                if (c == '#')
                {
                    x.insert(i), y.insert(j);
                    a.insert(i + j), b.insert(i - j);
                }
            }
        if ((get(x) < 2 && get(y) < 2) || get(a) < 2 || get(b) < 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}