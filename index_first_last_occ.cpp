#include<iostream>
#include<vector>
using namespace std;
    
vector<int> find(int arr[], int n , int x )
{
    
    int f=0 , l=n-1;
    while(f<=l)
    {
        if(arr[f]<x)
        {
            f++;
        }
        if(arr[l]>x)
        {
            l--;
        }
        if(arr[f]==x && arr[l]==x)
        {
            return{f,l};
            // cout<<"element found at "<<f<<" & "<<l<<" th index ";

        }
    }
    
    cout<<"-1"<<endl;
    // cout<<"No Element found";
}


int main()
{
    int n,x;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the the element to find occurance: ";
    cin>>x;

    int arr[n],i;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element: ";
        cin>>arr[i];
    }
    vector<int> ans;
    ans=find(arr,n,x);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}    