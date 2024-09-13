#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, c = 0, ans = 0;
    cin >> n;
    int a[n + 1] = {0};
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> x;
        a[x]++;
        if (a[x] == 1)
            c++;
        else if (a[x] == 2)
        {
            ans = max(ans, c);
            c--;
        }
    }
    cout << ans;
}
