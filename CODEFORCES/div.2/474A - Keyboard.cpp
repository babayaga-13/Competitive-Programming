#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S, s1 = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char x;
    cin >> x >> S;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < s1.size(); j++)
        {
            if (S[i] == s1[j] && x == 'R')
            {
                cout << s1[j - 1];
                break;
            }
            else if (S[i] == s1[j] && x== 'L')
            {
                cout << s1[j + 1];
                break;
            }
        }
    }
}
