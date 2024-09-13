#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,A=0,B=0;
        cin>>n;
        ll a[n],b[n];
        for(ll i=0;i<n;i++)
        {cin>>a[i];
         A+=a[i];}
         for(ll i=0;i<n;i++)
        {cin>>b[i];
         B+=b[i];}
         sort(a,a+n);
         sort(b,b+n);
         ll x=a[0];
         ll y=b[0];
         cout<<min((x*n+B),(y*n+A))<<endl;

    }
}
