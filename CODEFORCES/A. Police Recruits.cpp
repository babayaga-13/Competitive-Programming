#include<bits/stdc++.h>
using namespace std;
int main()
{
 
int n,k=0,untreated=0;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]!=-1){
        k+=a[i];
    }
    else{
        if(k==0){
            untreated++;
        }
        else{
            k--;
        }
 
    }
}
cout<<untreated;
   return 0;
}
