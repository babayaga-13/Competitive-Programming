#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c=0;
        cin>>n;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            if(a>b)
            c++;

        }
        cout<<c<<endl;
    }
}
