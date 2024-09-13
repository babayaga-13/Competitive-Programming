#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        auto it = s.upper_bound(y);
        if (it == s.begin())
            cout << "-1" << endl;
        else
        {
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
}