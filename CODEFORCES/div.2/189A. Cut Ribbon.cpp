#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d=1,s;
    cin>>n>>a>>b>>c;
    for(int i=0; i<=4000; i++)
        for(int j=0; j<=4000; j++)
        {
            s=n-a*i-b*j;
            if(s>=0&&s%c==0)
                d=max(d,i+j+s/c);
        }
cout<<d;
}
