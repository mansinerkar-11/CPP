#include<iostream>
using namespace std;
int main()
{
    int num,rev, final_rev=0,digit;
    cout<<"Enter number: ";
    cin>>num;
    
    while(num>0)
    {
        rev=num%10;
        num=num/10;
        final_rev=final_rev*10+rev;
    }
    while (final_rev>0)
    {
        digit=final_rev%10;
        final_rev=final_rev/10;
        if(digit==1)
        {
            cout<<"One ";
        }
        else if (digit==2)
        {
            cout<<"Two ";
            
        }
        else if (digit==3)
        {
            cout<<"Three ";
            
        }
        else if (digit==4)
        {
            cout<<"Four ";
            
        }
        else if (digit==5)
        {
            cout<<"Five ";
            
        }
        else if (digit==6)
        {
            cout<<"Six ";
            
        }
        else if (digit==7)
        {
            cout<<"Seven ";
            
        }
        else if (digit==8)
        {
            cout<<"Eight ";
            
        }
        else if (digit==9)
        {
            cout<<"Nine ";
            
        }
        else if (digit==0)
        {
            cout<<"Zero ";
            
        }
        
    }
    
    return 0;
}