#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, k, c = 0;
  cin >> t >> k;
  int a[t];
  for (int i = 0; i < t; i++)
    cin >> a[i];
  sort(a, a + t);
  int i = 0, j = t - 1;
  while (i <= j)
  {
    if (a[i] + a[j] <= k)
    {
      c++;
      i++;
      j--;
    }
    else
    {
      c++;
      j--;
    }
  }
  cout << c;
}