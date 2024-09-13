#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int t;
  cin >> t;
  int a[t];
  for (int i = 0; i < t; i++)
    cin >> a[i];
  for (int i = 0; i < t - 1; i++)
  {
    int min = i;

    for (int j = i + 1; j < t; j++)
    {
      if (a[j] < a[min])
        min = j;
    }
    if (min != i)
      swap(a[i], a[min]);
    for (int i = 0; i < t; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  cout << "SORTED : ";
  for (int i = 0; i < t; i++)
    cout << a[i] << " ";
}