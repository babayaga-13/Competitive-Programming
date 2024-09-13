#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m=0,r=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a<=10)
            {
                if(b>m)
                {m=b;
                r=i;}
            }
        }
        cout<<r<<endl;
    }
}
