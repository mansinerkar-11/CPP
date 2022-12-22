#include<iostream>
using namespace std;

int main()
{
    int rolln;
    cout<<"Enter Roll No.: ";
    cin>>rolln;
    if(rolln>0)
    {
        cout<<"Roll No is valid..!";
    }
    else
    {
        cout<<"Roll No cant be less than 0 or zero"<<endl;
    }
    return 0;
}