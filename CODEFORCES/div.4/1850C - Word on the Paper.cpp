#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        for(int j=0;j<8;j++)
        {
            for(int i=0; i<8; i++)
            {
                cin>>s[i];
                if(s[i]!='.')
                    cout<<s[i];
            }
        }
         cout<<endl;

    }
}
