#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c=0;
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        if(s1[0]==s1[1]&&s1[1]==s1[2]&&s1[0]!='.')
        {
            c++;
            cout<<s1[0]<<endl;
        }
        else if(s2[0]==s2[1]&&s2[1]==s2[2]&&s2[0]!='.')
        {
            c++;
            cout<<s2[0]<<endl;
        }
        else if(s3[0]==s3[1]&&s3[1]==s3[2]&&s3[0]!='.')

        {
            c++;
            cout<<s3[0]<<endl;
        }
        else  if(s1[0]==s2[0]&&s2[0]==s3[0]&&s1[0]!='.')
        {
            c++;
            cout<<s1[0]<<endl;
        }
        else  if(s1[1]==s2[1]&&s2[1]==s3[1]&&s1[1]!='.')
        {
            c++;
            cout<<s1[1]<<endl;
        }
        else  if(s1[2]==s2[2]&&s2[2]==s3[2]&&s1[2]!='.')
        {
            c++;
            cout<<s1[2]<<endl;
        }
        else  if(s1[0]==s2[1]&&s2[1]==s3[2]&&s1[0]!='.')
        {
            c++;
            cout<<s1[0]<<endl;
        }
        else  if(s1[2]==s2[1]&&s2[1]==s3[0]&&s1[2]!='.')
        {
            c++;
            cout<<s1[2]<<endl;
        }
        if(c==0)
            cout<<"DRAW"<<endl;
    }
}
