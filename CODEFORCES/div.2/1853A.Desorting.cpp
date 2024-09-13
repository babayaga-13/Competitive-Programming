#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c=0,d=INT_MAX;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
                {c++;}
             else
             {
                 d=min(d,(a[i+1]-a[i]));
             }
        }
        if(c!=0)
        cout<<"0"<<endl;
        else
        cout<<(d/2)+1<<endl;
    }
}
