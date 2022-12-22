#include<iostream>
using namespace std;
//function to reverse string 
string reveseWorld(string str)
{
    //method 1
    reverse(str.begin(), str.end());
    return str;
    //method 2
    //int n = str.length();
    //for (int i=0; i<n/2; i++)
    //swap(str[i], str[n-i-1]);
}
int main()
{
    string str;
    cout<<"Enter String To reverse: ";
    cin>>str;
    cout<<"Your reverse string is "<<reveseWorld(str)<<endl;
    return 0;
}