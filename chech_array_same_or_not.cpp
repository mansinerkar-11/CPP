#include<iostream>
#include<vector>
#define ll long long 
using namespace std;

class Solution{
    public:
    
    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
       sort(A.begin(),A.end());
       sort(B.begin(),B.end());
       return A==B;    // if output is 1 then arrays are same else not same
    }
};

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<ll> arr(n,0),brr(n,0);
    for(ll i=0;i<n;i++)
    {
        cout<<"Enter the element of first array: ";
        cin>>arr[i];
    }

    for(ll i=0;i<n;i++)
    {
        cout<<"Enter the element of second array: ";
        cin>>brr[i];
    }
    Solution ob;
    cout<<ob.check(arr,brr,n)<<"\n";
    return 0;
}