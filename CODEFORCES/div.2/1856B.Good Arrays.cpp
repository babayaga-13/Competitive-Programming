#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,s=0,c=0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
           cin>>a[i];
           s+=a[i];
           if(a[i]==1)
           c++;
        }
        if(s>=(n+c)&&n!=1)
        cout <<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
