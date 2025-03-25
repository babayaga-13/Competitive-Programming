#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e7 + 7;
bool prime[N];
vector<int> primes;

void sieve()
{
    fill(prime, prime + N, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < N; ++i)
    {
        if (prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int p : primes)
    {
        if (p > n)
            break;
        ans += n / p;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}