#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,i=0;
    cin>>n;
    while(sum<=n)
    {
        i++;
        sum+=(i*(i+1))/2;
    }
    cout<<i-1;
}
