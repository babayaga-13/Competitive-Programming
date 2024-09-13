#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,k;
        cin>>N>>k;
        for(int i=N;;N++)
        {
            int x=0;
            int n=N;
            while(n!=0)
            {
                x+=(n%10);
                n/=10;
            }
            if(x%k==0)
            {
                cout<<N<<endl;
                break;
            }
        }

    }
}
