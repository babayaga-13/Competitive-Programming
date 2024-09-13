#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] <= d)
        {
            c++;
            i++;
        }
    }
    cout << c;
}