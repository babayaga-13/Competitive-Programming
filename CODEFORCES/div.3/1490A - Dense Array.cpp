#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  int t;
  cin>>t;
  while(t--)
   {
    int n,ans=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        int x=a[i];
        int y=a[i+1];
        int mn=min(x,y);
        int mx=max(x,y);
        while(mn*2<mx)
        {
            ans++;
            mn*=2;
        }
    }
    cout<<ans<<endl;
   }
 }
