#include<iostream>
using namespace std;

int main()
{
    int i, sum, A[5]={1,1,1,1,1};
    {
        for(i=0; i<5; i++)
        {
            sum=sum+A[i];
        }
        cout<<sum<<endl;
    } 
    return 0;
}