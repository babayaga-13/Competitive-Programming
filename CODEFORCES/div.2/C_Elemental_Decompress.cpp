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
        vector<pair<int, int>> a(n);
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = {x, i};
        }
        sort(a.begin(), a.end());
        vector<int> p(n, 0), q(n, 0);
        set<int> s1, s2;
        for (int i = 0; i < n; i++)
        {
            s1.insert(i + 1);
            s2.insert(i + 1);
        }
        for (int i = 0; i < n; i++)
        {
            int x = a[i].first;
            int y = a[i].second;
            if (s1.find(x) != s1.end())
            {
                p[y] = x;
                q[y] = *s2.begin();
                if (p[y] < q[y])
                {
                    valid = false;
                    break;
                }
                s1.erase(x);
                s2.erase(*s2.begin());
            }
            else if (s2.find(x) != s2.end())
            {
                q[y] = x;
                p[y] = *s1.begin();
                if (p[y] > q[y])
                {
                    valid = false;
                    break;
                }
                s2.erase(x);
                s1.erase(*s1.begin());
            }
            else
            {
                valid = false;
                break;
            }
        }
        if (!valid)
        {
            no;
            continue;
        }
        yes;
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
        cout << endl;
    }
    return 0;
}
