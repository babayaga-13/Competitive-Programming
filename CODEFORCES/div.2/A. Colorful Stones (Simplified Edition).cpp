#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int i=0,j=0;
    /*while(t[j]!='\0')
    {
       if (s[i]==t[j])
       {
           i++;
       }
       j++;
    }*/
    for(int j=0; j<t.size(); j++)
    {
        if(s[i]==t[j])
            i++;
    }
    cout<<i+1;
}

