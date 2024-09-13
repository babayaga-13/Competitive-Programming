#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,sum=0,x,y;
        char s[11][11];
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                cin>>s[i][j];
                if(s[i][j]=='X')
                {
                    x=i;
                    y=j;
                    if(x>5)
                    x=11-x;
                    if(y>5)
                    y=11-y;
                    n=min(x,y);
                    if(n>5)
                    {
                        sum+=(11-n);
                    }
                    else
                    {sum+=n;}
                }
            }
        }
        cout<<sum<<endl;
    }
}
