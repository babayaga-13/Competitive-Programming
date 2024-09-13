#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,c=0;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]%2!=b[i]%2)
            {cout<<"NO"<<endl;c++;break;}
        }
        if(c==0)
            cout<<"YES"<<endl;
    }
}
