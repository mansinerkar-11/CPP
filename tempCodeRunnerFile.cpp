#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int a[]={4,5,0,7,2};
    sort(a,a+n-0);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}