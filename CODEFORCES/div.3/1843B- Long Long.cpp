#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        long long   sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=abs(a[i]);
        }
        int c=0,j;
        for(int i=0; i<n; i++)
        {
            if(a[i]<0)
            {
                for( j=i; j<n; j++)
                {
                    if(a[j]>0)
                    break;
                }
                c++;
                i=j;
            }
        }
        cout<<sum<<" "<<c<<endl;
    }
}
