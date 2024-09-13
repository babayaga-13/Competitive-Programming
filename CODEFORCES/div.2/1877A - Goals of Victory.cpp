#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s=0,x;
        cin>>n;
        for(int i=1;i<n;i++)
        {
        cin>>x;
        s+=x;
        }
    cout<<s*(-1)<<endl;
    }
}
