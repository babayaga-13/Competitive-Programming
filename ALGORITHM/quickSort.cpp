#include <bits/stdc++.h>
#define ll long long
using namespace std;

int partition(int a[], int l, int h)
{
  int x = a[h];
  int i = l - 1;
  for (int j = l; j < h; j++)
  {
    if (a[j]<= x)
    {
      i++;
      swap(a[j], a[i]);
    }
  }
  swap(a[h], a[i + 1]);
  return i + 1;
}
void quicksort(int a[], int l, int h)
{
  if (l < h)
  {
    int p = partition(a, l, h);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, h);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  quicksort(a, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
}