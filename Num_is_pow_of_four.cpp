//Given a number N, check if N is power of 4 or not.
#include<iostream>
using namespace std;
class Solution
{
    public:
    int isPowerOfFour(unsigned int n)
    {
       if (n == 0)
        return 0;
        while (n != 1) {
        if (n % 4 != 0)
            return 0;
        n = n / 4;
    }
    return 1;
    }
};
int main()
{
    int n;
    cout << "Enter Number: ";
    cin>>n;
    Solution ob;
    if(ob.isPowerOfFour(n))
    {
        cout<<"POWER OF FOUR" <<endl;
    }
	
    else
    {

    cout<<"NOT POWER OF FOUR"<<endl;
    }
	


    return 0;
}