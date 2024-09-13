#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  int t;
  cin>>t;
  while(t--)
   {
    int n,k,c=1,sum=0;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            c++;
        }
        else
        {
            if(c%2!=0)
            sum++;
             
             c=1;
        }
    
    }
    
        if((sum-k)<=1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
   }
 }
