#include<iostream>
using namespace std;

int main()
{
    int arr[]={7,10, 4 ,20 ,15};
    int temp,r=5,k=4;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<r;j++)
            {
                if(arr[i]<arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        int m=k-1;
        cout<<arr[m]<<endl;

        //2nd logic
        /*  

        sort(arr,arr+r+1);
        return arr[k-1]
        
        */
    return 0;
}