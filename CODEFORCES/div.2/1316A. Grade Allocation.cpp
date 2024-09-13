#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
    int n,m,x,s=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        {cin>>x;
        s+=x;}
        if(s<m)
            cout<<s<<endl;
        else
            cout<<m<<endl;
}
}
