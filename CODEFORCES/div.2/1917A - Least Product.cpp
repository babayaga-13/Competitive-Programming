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
    int n,z=0,neg=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {cin>>a[i];
    if(a[i]==0)
    z++;
    else if(a[i]<0)
    neg++;
   }

   if(z>0||neg%2!=0)
   cout<<"0"<<endl;
   else
   cout<<"1\n"<<"1 "<<"0"<<endl;
 }
}
