#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        priority_queue<ll> pq;
        pq.push(sum);
        while (!a.empty())
        {
            ll x = pq.top();
            pq.pop();

            int y = a.back();

            if (x < y)
            {
                break;
            }

            if (x == y)
            {
                a.pop_back();
                continue;
            }
            pq.push(x / 2);
            pq.push((x + 1) / 2);
        }

        if (a.empty())
            yes;
        else
            no;
    }

    return 0;
}
