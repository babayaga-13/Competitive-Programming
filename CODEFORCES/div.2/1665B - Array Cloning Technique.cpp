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
    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      mp[a[i]]++;
    }
    int m = 0;
    for (const auto it : mp)
    {
      m = max(m, it.second);
    }
    int ans = 0;
    while (m < n)
    {
      int r = n - m;
      int c = min(r, m);
      ans += 1 + c;
      m += c;
    }
    cout << ans << endl;
  }
}
