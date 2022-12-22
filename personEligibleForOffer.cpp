#include<iostream>
using namespace std;

int main()
{
    int age;
    cout<<"Enter Age: ";
    cin>>age;
    if(age<=0)
    {
        cout<<"Inavlid Age...Please Enter Correct age"<<endl;
        
    }
    else if( age<=12 || age>50)
    {
        cout<<"congratulations......You are Eligible for offer....."<<endl;
    }
    else
    {
        cout<<"Sorry....You are NOT Eligible for offer"<<endl;
    }
    return 0;
