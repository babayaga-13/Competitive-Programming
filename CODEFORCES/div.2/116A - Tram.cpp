#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int min=0,sum=0;
    while (t--)
    {
        int a,b;
     cin>>a>>b;
     sum=sum+b-a;
     min=max(min,sum);
    }
    cout<<min<<endl;
    
}
