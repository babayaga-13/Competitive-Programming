#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,s=0;
        cin>>n;
        while(n>=1)
        {
             s+=n;
             n=n/2;
        }
       cout<<s<<endl;
    }
}
