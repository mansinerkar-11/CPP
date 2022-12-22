// Given a number N.Find if the digit sum(or sum of digits) of N is a Palindrome number or not.
// Note:A Palindrome number is a number which stays the same when reversed.
#include<iostream>
using namespace std;

int main()
{

        int r=0,N,sum=0,sum2,rev;
        std::cout << "Enter Number: ";
        cin>>N;

        while(N!=0)
        {
            sum=sum+N%10;
            N=N/10;
        }
        sum2=sum;
        cout<<"Sum of digit is: "<<sum2<<endl;

        while(sum>0)
        {
            rev=sum%10;
            sum=sum/10;
            r = r*10 + rev;
        }
        if(sum2==r)
        {
            cout<<"Sum of the digit is  palindrome"<<endl;
        }
        else
        {
           cout<<"Sum of the digit is not palindrome"<<endl;
        }
    return 0;
}