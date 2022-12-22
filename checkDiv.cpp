#include<iostream>
using namespace std;
typedef float nume;
typedef float deno;
int main()
{
    nume num1;
    deno num2;
    float num3;
    cout<<"Enter numenetor:- ";
    cin>>num1;
    cout<<"Enter Denominator:- ";
    cin>>num2;
    if(num2==0)
    {
        cout<<"zero division error...!"<<endl;
    }
    else
    {
        num3=num1/num2;
        cout<<"Division of "<<num1<<" and "<<num2<<" is "<<num3<<endl;
    }
    return 0;
}