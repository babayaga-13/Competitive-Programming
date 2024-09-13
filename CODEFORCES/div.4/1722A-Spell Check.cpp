#include<bits/stdc++.h>
using namespace std;
int main()

    {int t;
    cin>>t;
    while(t--)
    {string s;
    string s1="Timur";
     int a,c=0;
    cin>>a;
    cin>>s;

    sort(s.begin(),s.end());
     sort(s1.begin(),s1.end());
     if(s==s1)
        cout<<"YES"<<endl;
     else
        cout<<"NO"<<endl;
    }
    }
