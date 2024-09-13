#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t,s=0,c=0;
 cin>>t;
 int m=1000;
 while(t--)
 { int x;
     cin>>x;
     s+=x;
     if(x%2!=0)
        {m=min(x,m);
        c++;}
 }
 if(c==0)
    cout<<"0";
  else if(c%2!=0)
    cout<<s;
 else if(c%2==0)
    cout<<s-m;

 }

