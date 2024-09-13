#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  int t;
  cin>>t;
  while(t--)
   {
    int n,c=0;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>=a[0]&&b[i]>=b[0])
        {c++; break;}
    }
    if(c!=0)
    cout<<"-1"<<endl;
    else 
    cout<<a[0]<<endl;
   }
 }
