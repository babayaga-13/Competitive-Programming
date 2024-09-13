#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,c=1;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=n-1;i>0;i--)
         {
             if(a[i]==a[i-1])
                c++;
             else
                break;
         }
         if(c==n)
            {cout<<"-1"<<endl; }
         else{
                cout<<n-c<<" "<<c<<endl;
         for(int i=0;i<n-c;i++)
            cout<<a[i]<<" ";
            cout<<endl;
        for(int i=n-c;i<n;i++)
            cout<<a[i]<<" ";
            cout<<endl;}

    }
}
