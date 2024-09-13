#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=0;
    string s;
    cin>>s;
    n=s.size();
    for(int i=1; i<s.size(); i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            c++;
    }

    if(c==(n-1))
    {
        for(int i=0; i<n; i++)
        {

            if(s[i]>='A'&&s[i]<='Z')
                s[i]+=32;
            else
                s[i]-=32;
          cout<<s[i];
        }
    }
    else cout<<s;


}
