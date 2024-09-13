#include <bits/stdc++.h>
#define ll long long
using namespace std;

void knapsack(int w[],int p[],int n,int x)
{    int dp[n + 1][x + 1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= x; j++)
            dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (w[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - w[i - 1]] + p[i - 1]));
        }
    }


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"TAKEN WEIGHT : ";
    
       int j=x;
    for (int i = n; i>0; i--) {
                     
        while(dp[i][j]==dp[i-1][j]){
            i--;
        }
        cout<<w[i-1]<<" ";

        j=j-w[i-1];

    }
    cout<<"\nMAX PROFIT = "<<dp[n][x];
}

int main()
{
    int n;
    cout << "ENTER SIZE = ";
    cin >> n;

    int w[n], p[n];

    cout << "ENTER WEIGHT = ";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << "ENTER PROFIT = ";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "MAX WEIGHT = ";
    int x;
    cin >> x;
    knapsack(w,p,n,x);

    
}