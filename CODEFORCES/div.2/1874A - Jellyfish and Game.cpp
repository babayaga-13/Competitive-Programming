#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        long long s = 0;
        cin >> x >> y >> n;
        int a[x], b[y];
        for (int i = 0; i < x; i++)
            cin >> a[i];
        for (int i = 0; i < y; i++)
            cin >> b[i];
        sort(a, a + x);
        sort(b, b + y);
        if (n >= 1)
        {
            if (a[0] < b[y - 1])
                swap(a[0], b[y - 1]);
        }
        sort(a, a + x);
        sort(b, b + y);
        if (n >= 2)
            swap(b[0], a[x - 1]);
        if (n % 2 != 0 && n > 2)
            swap(b[0], a[x - 1]);
        for (int i = 0; i < x; i++)
            s += a[i];
        cout << s << endl;
    }
}

