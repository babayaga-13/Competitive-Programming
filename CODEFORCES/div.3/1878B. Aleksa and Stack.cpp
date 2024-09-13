
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,s=1;
        cin>>n;

        for(int i=0; i<n; i++)

        {
            int n=s;
            cout<<n<<" ";
            s+=2;
        }
        cout<<endl;
    }
}
