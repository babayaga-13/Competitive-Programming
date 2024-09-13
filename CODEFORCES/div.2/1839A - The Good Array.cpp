#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
{
    int n,k;
    cin>>n>>k;
    double x=n-1;
    x=ceil(x/k)+1;
    cout<<x<<endl;
}
}
