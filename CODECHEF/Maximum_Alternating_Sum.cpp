#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
long long solve(vector<int> &v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    long long last = 0, first = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i >= n / 2)
        {
            last += v[i];
        }
        else
        {
            first += v[i];
        }
    }

    return last - first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        cout << solve(A) << endl;
    }

    return 0;
}
