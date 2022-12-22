#include<iostream>
using namespace std;

int main()
{
    float totalBillAmount;
    float discount = 0.0;

    cout<<"Enter Total Bill Amount: ";
    cin>>totalBillAmount;

    if(totalBillAmount<100)
    {
        cout<<"We are Sorry.....No discount on less than 100Rs shopping";
        cout<<totalBillAmount;
    }
    else if (totalBillAmount >= 100 && totalBillAmount < 500 )
    {
        cout<<"Congratulation you got 10% discount";
        (discount=totalBillAmount*10/100);
        cout<< "Bill to pay "<<(totalBillAmount-discount)<<endl;
    }
    else
    {
        cout<<"Congratulation you got 20% discount";
        (discount=totalBillAmount*20/100);
        cout<< "Bill to pay "<<(totalBillAmount-discount)<<endl;        
    }
    return 0;
}