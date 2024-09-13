#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y;
        long long s1=0,s2=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        { cin>>x;s1+=x;}
        for(int i=0;i<m;i++)
        { cin>>y;s2+=y;}
        if(s1>s2)
        cout<<"Tsondu"<<endl;
        else if(s1<s2)
        cout<<"Tenzing"<<endl;
        else
        cout<<"Draw"<<endl;
    }
}
