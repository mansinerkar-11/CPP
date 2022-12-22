#include<iostream>
using namespace std;

int main()
{
    int num,i;
    cout<<"Enter number: ";
    cin>>num;
    cout<<"Table of "<<num<<endl;
    for (i=1; i<=10; i++)
    {

        cout<<num*i<<endl;

    }
    cout<<"Finish"<<endl;
    return 0;
}