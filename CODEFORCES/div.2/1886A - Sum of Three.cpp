#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if((n-3)%3!=0&&(n-3)>2)
        cout<<"YES"<<endl<<"1 2 "<<n-3<<endl;
        else if((n-5)%3!=0&&(n-5)>4)
         cout<<"YES"<<endl<<"1 4 "<<n-5<<endl;
         else
          cout<<"NO"<<endl;
    }
}
