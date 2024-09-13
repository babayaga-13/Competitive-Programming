#include<bits\stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int a[m];
   for(int i=0;i<m;i++ )
    cin>>a[i];
    sort(a,a+m);
    int ans=INT_MAX;
    int j=0;
    for(int i=n-1;i<m;i++)
        {int d=a[i]-a[i-n+1];
     ans=min(ans,d);}

     cout<<ans<<endl;

}
