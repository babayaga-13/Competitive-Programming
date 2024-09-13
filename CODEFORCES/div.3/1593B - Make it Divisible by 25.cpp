#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int c = 0,d=0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (s[j] == '5' || s[j] == '0')
                    {
                        break;
                    }
                    else
                    {
                        c++;
                        i--;
                    }
                }
                break;
            }
            else
            {
                c++;
            }
        }
            for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '5')
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (s[j] == '2' || s[j] == '7')
                    {
                        break;
                    }
                    else
                    {
                        d++;
                        i--;
                    }
                }
                break;
            }
            else
            {
                d++;
            }
        }

        if(c==0&&d==0)
        cout<<"0"<<endl;
        else
        cout<<min(c,d)<<endl;
    }
}

