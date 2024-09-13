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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n % 2 == 0)
        {
            cout << "2\n";
            cout << "1 " << n << endl;
            cout << "1 " << n << endl;
        }
        else
        {
            cout << "4\n";
            cout << "1 " << n - 1 << endl;
            cout << "1 " << n - 1 << endl;
            cout << n - 1 << " " << n << endl;
            cout << n - 1 << " " << n << endl;
        }
    }
}