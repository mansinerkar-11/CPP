

#include<iostream>
using namespace std;

int main()
{
    int counter=1;
    for(int i=1; i<=3; i++)//For columns
    {
        for(int j=1; j<=3; j++)//for rows
        {
            cout<<counter<<" ";
            counter++;
        }
        
        cout<<endl;
    }
    
    return 0;
}