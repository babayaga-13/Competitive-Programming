#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    if(a.size()!=b.size())
        cout<<"No";
    else
    {
        int c=0;
        for(int i = 0; i < a.size(); i++)
        {
            if((a[i]=='a'||a[i]=='e'||a[i] == 'i'||a[i]=='u'||a[i]=='o')&&(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='u'||b[i]=='o'))
            c++;
            if((a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='u'&&a[i]!='o')&&(b[i]!='a'&&b[i]!='e'&&b[i]!='i'&&b[i]!='u'&&b[i]!='o'))
            c++;
        }
        if(c==a.size())
        cout<<"Yes";
        else cout<<"No";
    }
}
