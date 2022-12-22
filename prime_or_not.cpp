#include<iostream>
using namespace std;

int main()
{
    int num, i, count=0;
    cout<<"Enter number to check: ";
    cin>>num;
    for(i=1;i<=num; i++)
    {
        if(num%i==0)
        {
            count++;
        }
        
    }
    if(count==2)
    {
        cout<<"It is prime number "<<endl;
    }
    else
    {
        cout<<"It is not prime number "<<endl;
    }
    return 0;
}
