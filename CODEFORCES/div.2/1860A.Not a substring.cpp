#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        string a,b,t="()";
        int n=s.size();
        for(int i=0;i<n;i++)
        a+=t;
        for(int i=0;i<n;i++)
        b+='(';
          for(int i=0;i<n;i++)
        b+=')';
        if(a.find(s)==-1)
        cout<<"YES"<<endl<<a<<endl;
        else if(b.find(s)==-1)
        cout<<"YES"<<endl<<b<<endl;
        else 
        cout<<"NO"<<endl;

    }
}
