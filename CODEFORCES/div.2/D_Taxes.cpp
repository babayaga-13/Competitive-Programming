#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    if (prime(n))
        cout << "1";
    else if (prime(n - 2) || n % 2 == 0)
        cout << "2";
    else
        cout << "3";
}
