#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        char st=s[0];
        for(int i=1;i<s.size();i++)
        {

            if(st==s[i])
                {cout<<s[i];
             st=s[i+1];
             i++;}
        }
        cout<<endl;
    }
}
