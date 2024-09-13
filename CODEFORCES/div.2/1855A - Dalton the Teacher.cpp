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
        int a[n];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            if(a[i]==i)
                c++;
        }
        if(c%2==0)
            cout<<c/2<<endl;
        else
            cout<<c/2+1<<endl;
    }
}
