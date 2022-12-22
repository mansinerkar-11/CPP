#include<iostream>
using namespace std;

int main()
{
    int arr[10]={1,22,32,42,52,63,75,85,96,10};
    int l=0, h=10,k, mid;
    cout<<"Enter k: ";
    cin>>k;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(k==arr[mid])
        {
            cout<<"found at "<<mid<<endl;
            return 0;
        }
        else if (k<arr[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<"Key not found"<<endl;
    return 0;
}