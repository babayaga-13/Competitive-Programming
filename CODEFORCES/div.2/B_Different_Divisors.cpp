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
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int a = 1 + n;
        while (1)
        {
            if (prime(a))
                break;
            a++;
        }
        int b = a + n;
        while (1)
        {
            if (prime(b))
                break;
            b++;
        }
        cout << a * b << endl;
    }
}