#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxHappiness(int m, int x, vector<pair<int, int>> &offers)
{
    int earnings = 0;
    int maxHappiness = 0;

    for (int i = 0; i < m; ++i)
    {
        earnings += x;
        int remainingMoney = earnings;

        for (int j = i; j < m; ++j)
        {
            if (offers[j].first <= remainingMoney)
            {
                maxHappiness = max(maxHappiness, offers[j].second);
            }
        }
    }

    return maxHappiness;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, x;
        cin >> m >> x;
        vector<pair<int, int>> offers(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> offers[i].first >> offers[i].second;
        }

        // Calculate and output the maximum obtainable sum of happiness
        cout << maxHappiness(m, x, offers) << endl;
    }

    return 0;
}
