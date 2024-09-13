#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   cin>>s;
   string s1="hello";
   int j=0,c=0;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]==s1[j])
       {c++;j++;}
   }
   if(c==5)
    cout<<"YES";
   else
    cout<<"NO";
}
