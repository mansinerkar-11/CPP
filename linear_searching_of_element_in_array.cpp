//program to find the elements index value using linear search.
#include<iostream>
using namespace std;
int main()
{
    int a[10], i, n=10,key;
    cout<<"Enter elements of an array(integer): ";
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"Enter key to find: ";
    cin>>key;
    for(i=0; i<10; i++)
    {
        if(key==a[i])
        {
            cout<<"the possition of "<<key <<" is "<< i<<endl;
            return 0;
        }
    }
    cout<<"key not found "<<endl;
    return 0;
}