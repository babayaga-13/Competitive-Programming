#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{ 
  ios_base::sync_with_stdio(false);	cin.tie(NULL);
  int t;
  cin>>t;
  vector<int>v;
  for(int i=0;i<t;i++)
  {int u;
  cin>>u;
  v.push_back(u);
  }
  sort(v.begin(),v.end());
  int count=1;
  for(int i=0;i<t-1;i++)
   {
    if(v[i]!=v[i+1])
    count++;
   }
   cout<<count;
 }