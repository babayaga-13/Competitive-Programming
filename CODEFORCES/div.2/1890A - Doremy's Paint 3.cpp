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
        int n, c = 1,x=1;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++)

            cin >> v[i];
        sort(v,v+n);
        for(int i=0;i<n-1;i++)
        {
            if(v[i]!=v[i+1])
            x++;
        }
        if (x == 1)
            cout << "Yes" << endl;
        else if (x > 2)
            cout << "No" << endl;
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i] != v[i + 1])
                    break;
                else
                {
                    c++;
                }
            }
            if (c == floor(n / 2) || (n - c) == floor(n / 2))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
