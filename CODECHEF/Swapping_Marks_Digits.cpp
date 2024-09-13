#include <iostream>
#include <string>
using namespace std;

int reverse(int s)
{
    int x = (s % 10) * 10 + (s / 10);
    return x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int x = reverse(a);
        int y = reverse(b);
        a = max(a, x);
        b = min(b, y);
        if (a > b)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
