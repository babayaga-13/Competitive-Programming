#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6 + 2;
int prime[N] = {0};
ll pre[N] = {0}; 

void sieve()
{
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
    ll s = 0;
    for (int i = 2; i < N; i++) 
    {
        if (prime[i] == 0)
            s += i;
        pre[i] = s;
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
        int n;
        cin >> n;
        if (prime[n] == 0)
            cout << pre[n] * n << endl;
        else
            cout << pre[prime[n]] * n << endl;
    }
    return 0;
}
