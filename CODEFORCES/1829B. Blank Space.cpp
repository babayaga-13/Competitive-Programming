#include<bits/stdc++.h>
using namespace std;
int main()
 
    {int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int a[n];
       int d=0,c=0;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
       }
       for(int i=0;i<n;i++)
       {
           if(a[i]==0)
           {
               c++;
           }
           else{
            if(d<c)
                d=c;
            c=0;
           }
       }
       if(d<c)
                d=c;
                cout<<d<<endl;
 
    }
    }
