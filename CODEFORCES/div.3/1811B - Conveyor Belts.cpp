#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  int t;
  cin>>t;
  while(t--)
   {
    int n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    int p=min(min(x,y),min(n+1-x,n+1-y));
    int q=min(min(a,b),min(n+1-a,n+1-b));
    int ans=abs(p-q);
    cout<<ans<<endl;
   }
 }
