#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--)
    {
        int num_elements;
        cin >> num_elements;

        vector<int> elements(num_elements);
        for (int i = 0; i < num_elements; ++i)
            cin >> elements[i];

        stack<ll> value_stack;
        stack<int> index_stack;
        ll total_cost = 0;

        for (int i = 0; i < num_elements; ++i)
        {
            while (value_stack.size() > 1 && value_stack.top() > elements[i])
            {
                ll top_value = value_stack.top();
                value_stack.pop();
                if (top_value >= value_stack.top())
                {
                    index_stack.pop();
                }
                else
                {
                    value_stack.push(top_value);
                    break;
                }
            }
            value_stack.push(elements[i]);
            index_stack.push(i);
        }

        ll last_value = value_stack.top();
        value_stack.pop();
        int last_index = index_stack.top();
        index_stack.pop();

        while (!value_stack.empty())
        {
            total_cost += max(last_value, value_stack.top()) * (last_index - index_stack.top());
            last_value = value_stack.top();
            value_stack.pop();
            last_index = index_stack.top();
            index_stack.pop();
        }

        cout << total_cost << "\n";
    }
    return 0;
}
