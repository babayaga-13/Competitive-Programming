#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=5,d=5,k=1;
    float x;
    cin>>n;
    for( int i=2;s<n;i*=2)
    {
        s=s+5*i;
        k=i;
        if(s<n)
            d=s;
    }
    if(n<=5)
        d=0;
    x=n-d;
    x=(float)x/k;
    x=ceil(x);
    if (x==1)
        cout<<"Sheldon";
    else if(x==2)
        cout<<"Leonard";
    else if(x==3)
        cout<< "Penny";
    else if(x==4)
        cout<<"Rajesh";
    else if(x==5)
        cout<<"Howard";
}
