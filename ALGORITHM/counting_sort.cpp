#include <bits/stdc++.h> 
using namespace std;

void counting_sort(int a[], int b[], int k, int n)
{
    int count[k] = {0};
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        b[--count[a[j]]] = a[j];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
int main()
{
    int n;
    cout<<"Enter size= ";
    cin >> n;
    int a[n], b[n];
    int max = 0;
    cout<<"Enter value= ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    max++;
    counting_sort(a, b, max, n);
    cout<<"Sorted Array= ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}