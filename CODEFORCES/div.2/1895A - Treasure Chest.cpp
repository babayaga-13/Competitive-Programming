#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  ios_base::sync_with_stdio(false);	cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
   {
    int x,y,k;
    cin>>x>>y>>k;
    if(x>=y)
    cout<<x<<endl;
    else if(y-x<=k)
    cout<<y<<endl;
    else
    cout<<x+k+(y-x-k)*2<<endl;

   }
 }
