//program to check amstrong number.
#include<iostream>
using namespace std;

int main()
{
    int num,rev, sum=0 , temp;
    cout<<"Enter Number: ";
    cin>>num;
    temp = num;
    while (num>0)
    {
        rev=num % 10;
        num = num / 10;
        sum = sum+(rev*rev*rev);
        
    }
    cout<<sum<<endl;
    if (sum == temp)
    {
        cout<<"It is amstrong number"<<endl;
    }
    else
    {
        cout<<"No, it is not amstrong number"<<endl;
    }
    return 0;
}