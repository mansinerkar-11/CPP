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
    if (age>0 && age<=18)
    {
        cout<<"congratulations....!You are Young"<<endl;
    }
    else if(age>18)
    {
        cout<<"You are Old..."<<endl;
    }

    return 0;
}