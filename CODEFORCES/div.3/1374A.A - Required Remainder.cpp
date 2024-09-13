#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    ll x, y, n;
    cin >> x >> y >> n;
    ll m = (n - y) / x;
    ll k = m * x + y;
    cout << k << endl;
  }
  return 0;
}
