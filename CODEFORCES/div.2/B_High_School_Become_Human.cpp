#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    double x = b * log(a);
    double y = a * log(b);
    if (x == y)
        cout << "=" << endl;
    else if (x > y)
        cout << ">" << endl;
    else
        cout << "<" << endl;
}