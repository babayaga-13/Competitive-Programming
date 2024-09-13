#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int f=0,g=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='4')
            f++;
        else if(s[i]=='7')
            g++;
    }
    if(f==0&&g==0)
        cout<<"-1";
    else if(f>=g)
        cout<<"4";
    else
        cout<<"7";

}
