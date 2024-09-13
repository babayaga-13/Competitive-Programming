#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c=0;
        string s;
        cin>>s;
        if(s[0]=='a')
        c++;
        if(s[1]=='b')
        c++;
        if(s[2]=='c')
        c++;
        if(c>0)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;

    }
}
