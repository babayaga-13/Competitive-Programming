#include<bits/stdc++.h>
using namespace std;

int min_coins(int c[], int n, int x)
{
    int dp[n + 1][x + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= x; j++)
            dp[i][j] = INT_MAX;
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (c[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - c[i - 1]]);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[n][x];
}

int main()
{
    int n, x;
    cout << "Enter coin type : ";
    cin >> n;
    int c[n];
    cout << "Enter coins : ";
    for (int i = 0; i < n; i++)
        cin >> c[i];
    cout << "Enter amount : ";
    cin >> x;
    int minCoins = min_coins(c, n, x);
    cout << minCoins;
}
