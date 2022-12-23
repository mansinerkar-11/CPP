
#include<iostream>
using namespace std;

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
       if(n==0)
       {
           return 0;
       }
       while(n>1)
       {
           if(n%2==0){
               
           }
           else{
               return 0;
           } 
           n=n/2;
       }
       return 1;
    }
};

int main()
{ 
    long long num;
    cout<<"Enter Number: ";
    cin>>num;

    Solution ob;
        if(ob.isPowerofTwo(num))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    
    return 0;
}