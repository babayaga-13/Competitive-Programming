#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c = 0;
    cin >> n;
    while (n > 3)
    {
        c++;
        n -= 2;
    }
    cout << c + 1 << endl;
    for (int i = 0; i < c; i++)
        cout << "2 ";
    cout << n;
}