#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b,d,s=0,c=0;
    cin>>n>>b>>d;
    for(int i=0;i<n;i++)
   { int x;
    cin>>x;
    if(x<=b)
     {s+=x;
     if(s>d)
     {c++;
     s=0;}
     }
   }
   cout<<c;
}
