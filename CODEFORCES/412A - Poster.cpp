      #include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    if(n/2<t) 
    {
        for(int i=t;i<n;i++) 
            cout<<"RIGHT"<<endl;
        for(int i=n-1;i>=0;i--)
         {
            cout<<"PRINT"<<" "<<s[i]<<endl;
            if(i!=0)
                cout<<"LEFT"<<endl;
        }
    }
    else
     {
        for(int i=0;i<t-1;i++)
            cout<<"LEFT"<<endl;
        for(int i=0;i<n;i++) 
        {
            cout<<"PRINT"<<" "<<s[i]<<endl;
            if(i!=n-1)
                cout<<"RIGHT"<<endl;
        }
    }
}
