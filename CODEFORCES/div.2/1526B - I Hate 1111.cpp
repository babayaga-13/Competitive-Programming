#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  ios_base::sync_with_stdio(false);	cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
   {
    int n,c=0;
    cin>>n;
    while(n>=111)
    {
        if(n%11==0||n%11==0)
        {
            cout<<"YES"<<endl;
            c++;
            break;
        }
        else
        {
            n-=111;
        }
    }
    if(c==0)
    {
        if(n%11==0||n%111==0)
         cout<<"YES"<<endl;
        else
         cout<<"NO"<<endl;
    }
   }
 }
