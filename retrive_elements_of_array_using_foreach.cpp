#include<iostream>
using namespace std;

int main()
{
    int A[5]={1,2,3,4,5};
    for(int i : A)
    {
        cout<<i<<endl;
    }
    return 0;
}