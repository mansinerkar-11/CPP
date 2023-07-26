#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int a[]={7,6,5,4,3};
    sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}
