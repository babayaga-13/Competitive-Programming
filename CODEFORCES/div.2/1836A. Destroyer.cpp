#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  int t;
  cin>>t;
  while(t--)
   {
    int n;
    cin>>n;
    int a[102]={0};
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    string ans="YES";
    for(int i=0;i<101;i++)
    {
        if(a[i]<a[i+1])
        {   
            ans="NO";
            break;
        }
    }
    cout<<ans<<endl;
   }
 }
