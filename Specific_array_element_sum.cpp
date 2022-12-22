#include<iostream>
using namespace std;

int main()
{
    int temp=0;
    int arr[10]={1,2,3,4,5,6,7,8,9,11};
    for(int i=0;i<10;i++)
    {
        if(arr[i]==3)
        {
            temp=arr[i];
        }
        if(arr[i]==5){
            temp=temp+arr[i];
        }
        if(arr[i]==7){
            temp=temp+arr[i];
        }
    }
    cout<<"The addition of 3&5&7 is "<<temp<<endl;
    return 0;
}

// end of program