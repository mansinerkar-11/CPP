#include<iostream>
using namespace std;

int main()
{
    int num, rev;
    cout<<"Enter number to reverse: ";
    cin>>num;
    while (num>0)
    {
        rev= num % 10;
        num = num / 10;
        cout<<rev;    
    }
    cout<<endl;
    return 0;
}