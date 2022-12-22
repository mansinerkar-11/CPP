#include<iostream>

using namespace std;
int main()
{
    string str;
    cout<<"Enter Sentence: ";
    getline(cin,str);
    int m=str.size();    ///m is size
	   for(int i=0;i<m;i++)
	   {
	       if(i==0)
	       {
	           cout<<str[i];
	       }
	       else if(str[i]==' '){
	           cout<<str[i+1]<<endl;
	       }
	   }
    return 0;
}