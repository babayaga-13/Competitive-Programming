#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  int t;
  cin>>t;
  while(t--)
   {
    ll n;
    cin>>n;
    string ans="NO";
    for(ll i=1;i*i*i<=n;i++)
    {
        
        double b=cbrt(n-i*i*i);
        if(floor(b)==b&&b>0)
        ans="YES";
    }
    cout<<ans<<endl;
    
   }
 }
