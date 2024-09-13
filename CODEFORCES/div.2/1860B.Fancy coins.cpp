#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {int m,k,a1,ak,r,n;
    cin>>m>>k>>a1>>ak;
    int q=m/k;
    q=min(q,ak);
    m-=q*k;
    m-=a1;
    if(m<=0)
    cout<<'0'<<endl;
    else
    {
        if(m%k==0)
        cout<<m/k<<endl;
        else
        {
            int ans=0;
            ans=m/k;
            if(k-m%k<=a1)
            ans++;
            else
            ans+=(m%k);
            cout<<ans<<endl;
        }
    }
    }
}
