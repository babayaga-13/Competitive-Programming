#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  ios_base::sync_with_stdio(false);	cin.tie(NULL);
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];

  for(int i=1;i<n;i++)
  {
    int temp=a[i];
    int j=i-1;

    while(j>=0&&a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
    for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<endl;
  }
   for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
 }