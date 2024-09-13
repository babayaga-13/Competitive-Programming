#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        s="0"+s;
        int k=s.size();
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='5')
                {
                    for(int j=i;j<k;j++)
                    {s[j]='0';}
                    k=i;
                    s[i-1]++;
                }
        }
        if(s.front()=='0')
            s=s.substr(1);
        cout<<s<<endl;

    }
}
