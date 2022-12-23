/*
1 2 3 
4 5 6 
7 8 9


*/

#include<iostream>
using namespace std;

int main()
{
    int counter=1;
    for(int i=1; i<=3; i++)//For rows
    {
        for(int j=1; j<=3; j++)//for columns
        {
            cout<<counter<<" ";
            counter++;
        }
        
        cout<<endl;
    }
    
    return 0;
}