#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x,s;
    int num;
    cin>>x;
    int n=x.size();
    if(x[0]!='-')
    cout<<x;
    else
    {
     if(x[n-1]>x[n-2])
     {
        for(int i=0; i<n;i++)
        { if(i==(n-1))
           continue;
           s+=x[i];
        }
     }
     else if(x[n-1]<=x[n-2])
     {
        for(int i=0; i<n;i++)
        { if(i==(n-2))
           continue;
           s+=x[i];
        }
     }
     num=stoi(s);
    cout<<num;
    }
}
