#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,c=1;
        int m=1;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;i++)
            {
                if((a[i+1]-a[i])<=k)
                    c++;
                else
                c=1;
                 m=max(m,c);
            }
            cout<<n-m<<endl;
    }
}
