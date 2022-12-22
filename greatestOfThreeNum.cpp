#include<iostream>
using namespace std;

int main()
{
    float num1,num2,num3;
    cout<<"Enter 3 Numbers: ";
    cin>>num1>>num2>>num3;
    if (num1==num2 && num1==num3)
    {
        cout<<"All Numbers are same..."<<endl;
    }
    else if (num1>num2 && num1>num3)
    {
        cout<<"Greatest Number is "<<num1<<endl;
    }
    else if (num2>num3)
    {
        cout<<"Greatest Number is "<<num2<<endl;
        
    }
    else
    {
        cout<<"Greatest Number is "<<num3<<endl;
    }
    return 0;
}