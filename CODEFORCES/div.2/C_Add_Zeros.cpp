#include <iostream>
#include <vector>
using namespace std;

vector<int> max_possible_length(int t, vector<pair<int, vector<int>>> &test_cases)
{
    vector<int> results;

    for (int i = 0; i < t; ++i)
    {
        int n = test_cases[i].first;
        vector<int> &a = test_cases[i].second;

        int current_length = n; // Start with initial length of the array
        int max_length = n;

        // Iterate through the array to find positions that satisfy the condition dynamically
        for (int j = 1; j < n; ++j)
        { // Note that `j` starts from 1 because i > 1 as per problem statement
            if (a[j] == current_length + 1 - (j + 1))
            {
                // Update the current length by appending `j` zeros
                current_length += j;
                max_length = current_length;
            }
        }

        results.push_back(max_length);
    }

    return results;
}

int main()
{
    int t;
    cin >> t;
    vector<pair<int, vector<int>>> test_cases(t);

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
        }
        test_cases[i] = {n, a};
    }

    vector<int> results = max_possible_length(t, test_cases);

    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
