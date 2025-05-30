#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e6 + 5; // for small prime sieve
vector<int> primes;
bool is_prime[MAX];
unordered_map<int, int> dp; // frequency of product of primes
int ans = 0;
void sieve(int n = 1e6)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}
void compute(int x)
{
    vector<int> pf;
    int temp = x;
    for (int p : primes)
    {
        if (p * p > temp)
            break;
        if (temp % p == 0)
        {
            pf.push_back(p);
            while (temp % p == 0)
                temp /= p;
        }
    }
    if (temp > 1)
        pf.push_back(temp);

    int K = pf.size();
    for (int mask = 1; mask < (1 << K); ++mask)
    {
        int mu = 1;
        int bits = 0;
        for (int i = 0; i < K; ++i)
        {
            if (mask & (1 << i))
            {
                mu *= pf[i];
                bits++;
            }
        }
        if (bits % 2 == 1)
            ans += dp[mu];
        else
            ans -= dp[mu];
    }
    for (int mask = 1; mask < (1 << K); ++mask)
    {
        int mu = 1;
        for (int i = 0; i < K; ++i)
            if (mask & (1 << i))
                mu *= pf[i];
        dp[mu]++;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    for (int x : a)
    {
        compute(x);
    }
    int total_pairs = n * (n - 1) / 2;
    int coprime_pairs = total_pairs - ans;

    cout << coprime_pairs << '\n';
    return 0;
}
