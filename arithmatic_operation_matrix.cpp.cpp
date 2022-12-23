#include<iostream>
using namespace std;

void addition()






int main()
{
    int a[3][3]={{1 ,2 ,3 },{4 ,5 ,6 },{7 ,8 ,9 }};
    int b[3][3]={{3 ,2 ,1 },{6 ,5 ,4 },{9 ,8 ,7 }};
    int addition[3][3];

    //display the matrix a and b
    for(int m=0; m<3; m++)
    {
        for(int n=0;n<3;n++)
        {
            cout<<a[m][n]<<" ";
        }
        cout<<endl;
    }


    for(int p=0; p<3; p++)
    {
        for(int q=0;q<3;q++)
        {
            cout<<b[p][q]<<" ";
        }
        cout<<endl;
    }



    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3; j++)
        {
            addition[i][j]=a[i][j]+b[i][j];
        }
        cout<<endl;

    }
    return 0;
}