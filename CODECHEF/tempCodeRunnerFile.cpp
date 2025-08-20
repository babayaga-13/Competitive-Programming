void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = 1;
    for (int u : a)
    {
        int curr = ((1 - 2 * dp[u]) + MOD) % MOD;
        s *= curr % MOD;
    }

    int result = (1 - s + MOD) % MOD;
    result = (result * power(2, MOD - 2)) % MOD;

    cout << result << "\n";
}