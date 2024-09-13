#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N = 1e7 + 7;
int prime[N] = {0};
void sieve()
{
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int f = 0;
        for (int i = l; i <= r; i++)
        {
            if (prime[i] == 0)
                continue;
            else
            {
                cout << prime[i] << " " << i - prime[i] << endl;
                f++;
                break;
            }
        }
        if (f == 0)
            cout << "-1\n";
    }
}