#include <vector>
#include<iostream>
using namespace std;
int main(){
vector<string> myvector;
myvector.push_back("a"); 
myvector.push_back("b");
myvector.push_back("c");
myvector.push_back("d");
vector<string>::iterator it;
int n=3,i=0;
for(it = myvector.begin();it != myvector.end();it++,i++) // found nth element..print and break.
if(i == n) 
{
cout<<*it << endl; // prints d.
break;

// testing git
} 
}


