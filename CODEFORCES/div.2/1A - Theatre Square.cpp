#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    n = ceil((double)n / a);
    m = ceil((double)m / a);
    cout << n * m;
}