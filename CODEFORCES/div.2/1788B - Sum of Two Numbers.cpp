#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,a=0,b=0;
        cin >> n;
        string s = to_string(n);
        int m=s.size();
        vector<int> v1, v2;
        bool f = false; 

        for (int i = 0; i < m; i++) {
            int x = s[i] - '0';
            
            if (x % 2 == 0) {
                v1.push_back(x / 2);
                v2.push_back(x / 2);
            } else {
                if (f) {
                    v1.push_back((x + 1) / 2);
                    v2.push_back(x / 2);
                } else {
                    v1.push_back(x / 2);
                    v2.push_back((x + 1) / 2);
                }
                f = !f;
            }
        }
        for(auto u:v1)
         a=a*10+u;
        for (auto u : v2) 
         b=b*10+u;
        cout<<b<<" "<<a<<endl;
    }  
}
