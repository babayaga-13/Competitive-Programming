#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string x, y;
    cout << "String 1 : ";
    cin >> x;
    cout << "String 2 : ";
    cin >> y;
    int m = x.size(), n = y.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout<< dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Size of LCM = " << dp[m][n] << endl;
    int i = m, j = n;
    string ans;
    while (i != 0 && j != 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans += x[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout << "Longest common subsequence = " << ans << endl;
    return 0;
}