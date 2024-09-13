#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cl=0,cu=0;
string a;
cin>>a;
int n =a.size();
 
for(int i=0;i<n;i++){
    if(isupper(a[i]))
        cu++;
    else
    cl++;
}
if (cl>=cu)
        transform(a.begin(),a.end(),a.begin(),::tolower);
else
     transform(a.begin(),a.end(),a.begin(),::toupper);
    cout<<a;
}
