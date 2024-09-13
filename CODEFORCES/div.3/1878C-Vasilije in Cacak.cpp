#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,x,s=0;
        cin>>n>>k>>x;
        long long  z=(k*(k+1))/2;
        s=(k*(2*(n+1-k)+(k-1)))/2;

        if(x>=z&&x<=s)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
