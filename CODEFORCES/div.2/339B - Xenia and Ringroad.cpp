#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,s=1,c=0;
    cin>>m>>n;;
    for(int i=0;i<n;i++)
    {   
        int x;
        cin>>x;
        if(x==s)
        continue;
        if(x>s)
        {c+=x-s;
        s=x;}
        else if(x<s)
        {c+=m-s+x;
           s=x; }
    }
    cout<<c;
    return 0;

}
