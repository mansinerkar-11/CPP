#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"How many task do you want to perform: ";
    cin>>size;

    int BT[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter Burst time of task "<<i+1<<" : ";
        cin>>BT[i];
    }

    cout<<"\n\nAssume that all tasks are arrive at same time\n";

    int WT[size+1];
    WT[0]=0;
    WT[1]=BT[0];
    
    for(int i=2;i<size+1;i++)
    {
        
        WT[i]=WT[i-1]+BT[i-1];
        
    }

    
    //for TAT
    int TAT[size];
    float sum=0;
    for(int i=0;i<size;i++)
    {
        TAT[i]=WT[i]+BT[i];
        sum=sum+TAT[i];
    }
    cout<<"_______________________________________________________________________________________\n";
    cout<<"\n  TASK\t|\tBURST TIME\t|\tWAITING TIME\t|\tTURN AROUND TIME  "<<endl;
    cout<<"_______________________________________________________________________________________";
        for(int i=0;i<size;i++)
        {
            cout<<"\nT"<<i+1<<"\t|\t\t"<<BT[i]<<"\t|\t\t"<<WT[i]<<"\t|\t\t"<<TAT[i]<<endl;
        }


    cout<<"\n\nAverage Turn Around Time: "<<sum/size<<endl;
}