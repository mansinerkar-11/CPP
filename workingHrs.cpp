#include<iostream>
using namespace std;

int main()
{
    int hrs;
    cout<<"Enter Your Working hours: ";
    cin>>hrs;
    if(hrs>23 || hrs<0)
    {
        cout<<"Invalid Hours.."<<endl;
    }    
    else if (hrs>9  && hrs<18)
    {
        cout<<"You are in working hours...!"<<endl;
    }
    else
    {
        cout<<"You are NOT in working hours...!"<<endl;
    }
    return 0;
}