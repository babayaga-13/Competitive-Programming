#include<bits/stdc++.h>
using namespace std;
void max_heapify(int a[],int n,int i)
{
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(left<n&&a[left]>a[largest])
    largest=left;
    if(right<n&&a[right]>a[largest])
    largest=right;
    if(largest!=i)
    {
    swap(a[i],a[largest]);
    max_heapify(a,n,largest);
    }
}
void build_max(int a[],int n)
{
 for(int i=(n/2)-1;i>=0;i--)
   {
        max_heapify(a,n,i);
    }

}
void heap_sort(int a[],int n)
{
    build_max(a,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        n=n-1;
        max_heapify(a,n,0);
    }
}
int main()
{
    int n;
    cout<<"Number of element=";
    cin>>n;
    int a[n];
    cout<<"Enter elements = ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    heap_sort(a,n);
    cout<<"MAx Heap=";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
