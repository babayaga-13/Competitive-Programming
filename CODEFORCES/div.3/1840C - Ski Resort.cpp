#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,q,c=0,ans=0;
        cin>>n>>k>>q;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]<=q)
            {
                c++;
                if(c>=k)
                    ans+=(c-k+1);
                 if(i==(n-1))
                        c=0;
            }
            else
                c=0;
        }
        if(c>=k)
         {c=c-k+1;
        ans+=c*(c+1)/2;
       }

        cout<<ans<<endl;
    }
}
