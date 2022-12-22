#include<iostream>
using namespace std;

int main()
{
    int num, i, sum=0;
    cout<<"Enter Number: ";
    cin>>num;
    for (i=0; i<=num; i++)
    {
        sum =sum+ i;

    }
    cout<<"Sum of first "<<num<<"Number is "<<sum<<endl;
    return 0;
}               