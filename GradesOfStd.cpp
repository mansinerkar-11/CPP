#include<iostream>
using namespace std;

int main()
{
    float sub1,sub2,sub3,sub4,sub5,total,avg;
    cout<<"Enter marks of 5 subjects: "<<endl;
    cin>>sub1>>sub2>>sub3>>sub4>>sub5;
    total = sub1+sub2+sub3+sub4+sub5;
    avg=total/5;

    if( avg>=60)
    {
        cout<<"A Grade"<<endl;
    }
    else if (35 <= avg < 60)
    {
        cout<<"B Grade"<<endl;   
    }
    else
    {
        cout<<"c Grade"<<endl;
    }



    return 0;
}