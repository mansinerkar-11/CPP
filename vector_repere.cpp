
//Vector:Sequence Container

#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6}; // standard Carray 
    vector<int> v(arr, arr+5); // Initialize vector with Carray
     cout<<v.back() <<" "<<endl;   //output last element of vector
     cout<<"Element is poped....!"<<endl;
     v.pop_back();
     cout<<"\nArray after pop operation..."<<endl;
    while (!v.empty() )            //until vector is empty
    {
            for(int i=0; i<v.size(); ++i) 
            cout<<v[i]<<" "<<endl; 
        return 0;
    }

}
