#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = 0;
    for (int b = 0; b < n; b++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (i % k != b % k)
                sum += a[i];
        m = max(m, abs(sum));
    }

    cout << m << endl;
}
