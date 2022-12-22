#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float a,b,c,d,r1,r2;
    cout<<"Enter Value of A, B, C : ";
    cin>>a>>b>>c;
    d=b*b-4*a*c;

    if(d==0)
    {
        cout<<"Roots are real and equal..."<<endl<<'(-b/(2*a))<<endl;
    }
    else if (d>0)
    {
        cout<<"Roots are real and unequal.."<<endl<<(-b+sqrt(d)/(2*a))<<endl<<(-b+sqrt(d)/(2*a))<<endl;
        
    }
    else
    {
        cout<<"Imaginarryyyy....."<<endl ;
    }
    return 0;
}