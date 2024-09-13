#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c,s,y;
    cin >> a >> b >> c;
    s= max (a * b * c, (a + b) * c);
    y=max((a + b * c),(a * (b + c)));
    s=max(s,y);
    s=max(s,( a + b + c));
	cout << s;
    return 0;
}
