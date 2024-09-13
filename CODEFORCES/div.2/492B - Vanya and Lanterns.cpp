#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n,l,m;
        cin>>n>>l;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
         m=2*max(a[0],l-a[n-1]);
        for(int i=0;i<n-1;i++)
        {
            m=max(m,(a[i+1]-a[i]));
        }
        printf("%.10f\n",(double)m/2);

    }
