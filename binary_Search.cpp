#include<iostream>
using namespace std;

int main()
{
    int size,i,j;
    cout<<"Enter the size of an array: ";
    cin>>size;
    int  arr[size];
    for ( i=0; i<size; i++)
    {
        cout<<"Enter Element: ";
        cin>>arr[i];
    }

//Dispplay the array
    cout<<"\nYour array is: ";
    for(j=0;j<size; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    
//sort array in assending order
   int m, n, min, temp;
   for (m = 0; m < size - 1; m++) {
      min = m;
      for (n = m + 1; n < size; n++)
      if (arr[n] < arr[min])
      min = n;
      temp = arr[m];
      arr[m] = arr[min];
      arr[min] = temp;
   }

//Dispplay the Sorted array ****Using selection sort*****
    cout<<"\nYour Sorted array is: ";
    for(j=0;j<size; j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<"\n"<<endl;


//Binary Search
    int key,low=0,heigh=size,mid;
    cout<<"Enter key to find: ";
    cin>>key;
    while(low<heigh)
    {
        mid=(low+heigh)/2;
        if(key==arr[mid])
        {
            cout<<"Element found at: "<<mid<<"th Index"<<endl;
            return 0;
        }
        else if(key<arr[mid])heigh=mid-1;
        else low=mid+1;
    }
    cout<<"Element Not Found"<<endl;
    return 0;
}