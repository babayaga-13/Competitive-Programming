#include<bits\stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int c=0,f,l,sum;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        c++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {f=i; break;}
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='1')
        {l=i; break;}
    }
    sum=l-f+1;
    sum-=c;
    if(c==0)
        cout<<"0"<<endl;
    else
    cout<<sum<<endl;;

  }
}
