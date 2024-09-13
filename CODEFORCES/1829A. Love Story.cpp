#include<bits/stdc++.h>
using namespace std;
int main()

    {int t;
    cin>>t;
    while(t--)
    {
        string s="codeforces";
        string s1;int c=0;
        cin>>s1;
        for(int i=0;i<10;i++)
        {

                if(s[i]!=s1[i])
                {c++;}
            }

        cout<<c<<endl;
    }
    }




