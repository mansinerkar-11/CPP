#include<iostream>
using namespace std;

class Solution{
  public:
  int num1=0, num2=0;
    /*You are required to complete below function */
    int multiplyStrings(string s1, string s2) {
       //Your code here
       
       for(int i=0; i<s1.length(); i++)
       {
           if(s1[i]-'0'>=1 && s1[i]-'0'<=9)
           {
               num1=num1*10+s1[i]-'0';
           }else{
               return 0;
           }
       }
       
       for (int j=0; j<s2.length();j++)
       {
           if(s2[j]-'0'>=1 && s2[j]-'0'<=9)
           {
               num2=num2*10+s2[j]-'0';
           }else{
               return 0;
           }
       }
       int num3=num1*num2;
       return num3;
    }

};


int main()
{
    string string1;
    string string2;
    cout<<"Enter First Number: ";
    cin>>string1;
    cout<<"Enter Second Number: ";
    cin>>string2;
    Solution obj;
    cout<<"Multiplication is : "<<obj.multiplyStrings(string1, string2)<<endl;
    
    return 0;
}