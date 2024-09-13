#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,a,b,sum=0,x;
    cin>>n>>m>>a>>b;
   if(m*a<=b)
   cout<<n*a;
   else
   {
    x=(n/m)*b+min((n%m)*a,b);
    cout<<x;
   }
}
