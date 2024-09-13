#include <iostream>
using namespace std;

int isSubsetSum(int array[], int t, int s)
{
    int dp[t + 1][s + 1];

    // Initializing the dp table
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = 0;
        }
    }

    // A sum of 0 is always possible with an empty subset
    for (int i = 0; i <= t; i++)
        dp[i][0] = 1;

    // Filling the dp table
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (array[i - 1] == j)
                dp[i][j] = 1;
            else if (array[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - array[i - 1]];
        }
    }

    // Printing the dp table
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[t][s];
}

int main()
{
    int t;
    cout << "Enter the number of elements: ";
    cin >> t;

    int array[t];
    cout << "Enter the elements: ";
    for (int i = 0; i < t; i++)
        cin >> array[i];

    int s;
    cout << "Enter the target sum: ";
    cin >> s;

    int result = isSubsetSum(array, t, s);

    if (result == 1)
        cout << "Subset with sum " << s << " exists." << endl;
    else
        cout << "Subset with sum " << s << " does not exist." << endl;

    return 0;
}
