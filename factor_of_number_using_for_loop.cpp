//Program to check the factor..
//eg:- if number is 8 then to find that which can perfectly divide 8 till 8 number 
#include<iostream>
using namespace std;

int main()
{
    int num,i;
    cout<<"Enter number: ";
    cin>>num;
    for (i=1; i<=num; i++)
    {
        if(num % i == 0)
        {
            cout<<num<<" is perfectly divisible by "<<i<<endl;
        } 
        
    }
    return 0;
}