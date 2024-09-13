#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   cin>>s;
  transform(s.begin(),s.end(),s.begin(),::tolower);
   string s1;
   for(int i=0;i<s.size();i++)
   {if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y')
       {
       s1=s1+'.';
       char d=s[i];
       s1=s1+d;
       }
       }
   cout<<s1;
}
