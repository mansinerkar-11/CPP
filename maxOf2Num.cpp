#include<iostream>
using namespace std;

int main()
{
    float num1,num2;
    cout<<"Enter 2 Numbers: ";
    cin>>num1>>num2;
    if (num1>num2)
    {
        cout<<num1<<" is greater...."<<endl;
    }
    else
    {
        cout<<num2<<" is greater..."<<endl;
    }
    return 0;
}