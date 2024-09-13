#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long t,s,x=0;
   cin>>t>>s;
   while(t--)
   {
     char c;
     long long n;
     cin>>c>>n;
     if(c=='-'&&s<n)
       x++;
     else if(c=='-'&&s>=n)
        s-=n;
     else
        s+=n;
 
   }
   cout<<s<<" "<<x;
}
