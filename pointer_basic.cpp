#include<iostream>
using namespace std;

int main()
{
    int x=10;       //initialize x is 10
    int *p;   //setting the pointer
    p=&x;        //memory of x is stored in the p
    cout<<"Value of x is: "<<x<<endl;
    cout<<"Memeory size of x is: "<<&x<<endl;
    cout<<"Your pointer is in: "<<p<<endl;
    cout<<"Memory size of p: "<<&p<<endl;
    cout<<"The data where p is pointing: "<<*p<<endl;
    return 0;
}