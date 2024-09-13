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
        for(int i=0;i<2*n;i++)
        {
            int a;
            cin>>a;
            if(a%2==0)
            c++;
            else 
            c--;
        }
        if(c==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
