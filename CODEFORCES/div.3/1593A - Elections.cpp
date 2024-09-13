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
    int a,b,c;
    cin>>a>>b>>c;
    int x,y;
    x=b-a;
    y=c-a;
    if(max(x,y)<0)
    cout<<"0 ";
    else
    cout<<max(x,y)+1<<" ";
    x=a-b;
    y=c-b;
    if(max(x,y)<0)
    cout<<"0 ";
    else
    cout<<max(x,y)+1<<" ";
    x=b-c;
    y=a-c;
    if(max(x,y)<0)
    cout<<"0 ";
    else
    cout<<max(x,y)+1<<" ";

    cout<<endl;
    
   }
 }
