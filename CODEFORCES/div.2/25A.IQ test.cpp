#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c1=0,c2=0;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
       {cin>>a[i];
       if(a[i]%2==0)
        c1++;
       else
        c2++;}
       for(int i=1;i<=n;i++)
       {
           if(c1==1&&a[i]%2==0)
            cout<<i;
           else if(c2==1&&a[i]%2!=0)
            cout<<i;
       }
}
