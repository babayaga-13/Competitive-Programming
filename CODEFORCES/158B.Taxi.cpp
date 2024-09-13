#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t,a=0,b=0,c=0,d=0,s;
 cin>>t;
 int ar[t];
 for(int i=0;i<t;i++)
    {cin>>ar[i];
    if(ar[i]==4)
        a++;
    else if(ar[i]==3)
        b++;
    else if(ar[i]==2)
        c++;
    else
        d++;
    }
    a=a+b;
    if(b>=d)
        d=0;
    else
        d=d-b;
    if(c%2==0)
     {a=a+c/2;
     c=0;}
    if(d%4==0)
      {a=a+d/4;
       d=0;}
     a+=c/2;
     c-=(c/2)*2;
     a+=d/4;
     d-=(d/4)*4;
     s=c*2+d;
     a+=ceil((float)s/4);
     cout<<a;

}
