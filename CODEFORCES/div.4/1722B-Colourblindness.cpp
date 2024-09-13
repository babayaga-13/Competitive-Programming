#include<bits/stdc++.h>
using namespace std;
int main()

    {int t;
    cin>>t;
    while(t--)
    {
        int n,c=0;
    string s;
    string s1;
    cin>>n>>s>>s1;
    for(int i=0;i<n;i++)
    {
        if((s[i]=='R'&&s1[i]!='R')||(s1[i]=='R'&&s[i]!='R'))
            { c++ ;
            cout<<"NO"<<endl;
            break;
        }
    }
    if(c==0)
        cout<<"YES"<<endl;

    }
    }




 
