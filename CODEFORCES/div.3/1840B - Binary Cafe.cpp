#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     long long n;
     int k;
     cin>>n>>k;
     long long x;
     k=min(k,40);
     x=pow(2,k);
     cout<<min(n+1,x)<<endl;
    }
}
