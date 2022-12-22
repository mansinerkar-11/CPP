#include<iostream>
using namespace std;

int main()
{
    int choice;
    cout<<"1. Addition\n"<<"2. Subtraction\n"<<"3. Multiplication\n"<<"4. Division\n"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>choice;

    float a,b,c;
    cout<<"Enter Two numbers: ";
    cin>>a>>b;
    switch (choice)
    {
    case 1: c=a+b;
        break; 
    case 2: c=a-b;
        break; 
    case 3: c=a*b;
        break; 
    case 4: c=a/b;
        break; 
    default:"Invalid input";
        break;
    }
    cout<<c<<endl;
    return 0;
}