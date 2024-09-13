#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 1;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (x == a[i])
            {
                x += 1;
            }
            b[i] = x;
            x++;
        }
       
        cout << b[n-1] <<endl;
    }
    
}
