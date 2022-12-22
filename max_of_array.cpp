//program to find the largest elements of an array,.
#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,3,4,55,6,7,} ,i ,max=arr[0];
    for(i=1; i<7; i++)
    {

        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<"largest element of an array is "<<max<<endl;

    return 0;
}