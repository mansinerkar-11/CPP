//program to perform shell sort

#include<iostream>
using namespace std;

void printarray(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int shellsort(int n,int arr[])
{
    int k=0;
    for (int gap = n/2; gap > 0; gap /= 2)
    {  
        
        for (int i = gap; i < n; i += 1)
        {  
            
            int temp = arr[i];
            int j;      
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
            cout<<"Pass"<<k<<" : ";
            k++;
            printarray(n,arr);
            cout<<endl;
        }
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    cout<<"Your array : ";
    printarray(n,arr);
    cout<<"Your sorted array : ";
    shellsort(n,arr);
    printarray(n,arr);
    return 0;
}