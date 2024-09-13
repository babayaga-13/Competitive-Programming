#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t,a=0,b=0,c=0;
  cin>>t;
  while(t--)
  {
      int x,y,z;
      cin>>x>>y>>z;
      a+=x;b+=y;c+=z;
  }
  if(a==0&&b==0&&c==0)
    cout<<"YES";
    else
    cout<<"NO";
}
