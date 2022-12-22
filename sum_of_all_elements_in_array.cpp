//program to calculate sum of all the elements of an array.
#include<iostream>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5}, sum=0,i;
    for(auto i:a)
    {
        sum=sum+i;
    }
    cout<<"sum of the all elements in array is "<<sum<<endl;
    
    return 0;
}