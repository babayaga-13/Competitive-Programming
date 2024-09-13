#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], col[n] = {0}, c = 1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 2; i * i <= 1000; i++)
        {
            int f = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] % i == 0 && !col[j])
                {
                    col[j] = c;
                    f = 1;
                }
            }
            if (f)
                c++;
        }
        cout << c - 1 << endl;
        for (int j = 0; j < n; j++)
            cout << col[j] << " ";
        cout << endl;
    }
}