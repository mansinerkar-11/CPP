/* program to find the sum of factor till n* and check it is that perfect or not */
#include<iostream>
using namespace std;

int main()
{
    int num,i,sum=0;
    cout<<"Enter number: ";
    cin>>num;
    for(i=1; i<=num; i++)
    {
        if(num%i==0)
        {
            sum+=i ;
        }
    }
    cout<<"sum of all factor till "<<num<<" is "<<sum<<endl;
    if(2*num==sum)
    {
        cout<<"Perfect number"<<endl;
    }
    else
    {
        cout<<"Not perfect number"<<endl;
    }
    return 0;
}