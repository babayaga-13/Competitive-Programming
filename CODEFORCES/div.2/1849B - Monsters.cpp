#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x % k == 0)
            {
                x = k;
            }
            else
            {
                x = x % k;
            }

            a.push_back({-x, i});
        }

        sort(a.begin(),a.end());
        
            for (int i = 0; i < n; i++)
            {
            
                cout << a[i].second + 1 <<" "; 
            }
        
        cout<<endl;
    }
}
