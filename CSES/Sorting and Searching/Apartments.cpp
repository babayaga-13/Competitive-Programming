#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k, c = 0;
    cin >> n >> m >> k;
    
    ll a[n], b[m];
    
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + m); 
    ll j=0,i=0;
    while(i<n&&j<m)
    { 
        if(a[i]-b[j]>k)
         j++;
        else if(b[j]-a[i]>k) 
        i++;
        else
        {c++;
        i++;
        j++;}
       
    }
    
    cout << c;

    return 0;
}
