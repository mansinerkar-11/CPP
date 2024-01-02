//Name: Mansi Dinesh Nerkar        Div:B     Roll no: 77

#include<iostream>
using namespace std;

class complex
{
	private:
	float real;
	float img;
	
	public:
	complex()
	{
		real=0;
		img=0;
	}
	friend istream &operator>>(istream&in,complex&c);
	friend ostream &operator<<(ostream&out,complex&c);
	complex operator+(complex t);
	complex operator*(complex t);

	
	/*void input()
	{	cout<<"enter real and imagenary part :";
		cin>>real>>img;
	}
	void display()
	{
		cout<<real<<"+"<<img<<"i";
		cout<<endl;
	}
	friend complex sumcp(complex c1 , complex c2);
	friend complex multcp(complex c1 , complex c2);*/
};
istream &operator>>(istream&in,complex&c)
{
	cout<<"\n Enter real and imaginary parts of number:";
	in>>c.real>>c.img;
}
ostream &operator<<(ostream&out,complex&c)
{
	cout<<"\n The complex no is:";
	out<<c.real<<"+"<<c.img<<"i";
}
complex complex::operator*(complex t)
{
	complex temp;
	temp.real=(real*t.real)-(img*t.img);
	temp.img=(real*t.img)+(t.real*img);
	return temp;
}
complex complex::operator+(complex t)
{
	complex temp;
	temp.real=real+t.real;
	temp.img=img+t.img;
	return temp;
}

/*complex sumcp(complex c1 , complex c2)
{
	complex c3;
	c3.real=c1.real+c2.real;
	c3.img=c1.img+c2.img;
	return c3;
}
complex multcp(complex c1 , complex c2)
{
	complex c3;
	c3.real=(c1.real*c2.real)-(c1.img*c1.img);
	c3.img=(c1.img* c2.real)+(c1.real*c2.img);
	return c3;
}
*/
int main()
{	char ask;
complex c1,c2,c3;
do
{
	cout<<"\n 1st complex number:";
	cin>>c1;
	cout<<"\n 2st complex number:";
	cin>>c2;
	int choice;
	cout<<"\n Enter the operator:\n 1.Add \n 2.Multiplication\n";
	cin>>choice;

    switch(choice)
	{
		case 1: cout<<"\n Addition c1 + c2:";
			c3=c1+c2;
			cout<<c3;
			break;		
		case 2: cout<<"\n Multiplication c1 * c2:";
			c3=c1*c2;
			cout<<c3;
			break;	
		default:
			break;
	}
    cout<<"\nEnter choice[Y/N]:";
    cin>>ask;
}while(ask=='y' || ask=='Y');
return 0;

}


/* 1st complex number:
 Enter real and imaginary parts of number:10 10 

 2st complex number:
 Enter real and imaginary parts of number:20 20 

 Enter the operator:
 1.Add 
 2.Multiplication
1

 Addition c1 + c2:
 The complex no is:30+30i
Enter choice[Y/N]:y
*/
/*
1st complex number:
 Enter real and imaginary parts of number:5 5

 2st complex number:
 Enter real and imaginary parts of number:2 2   

 Enter the operator:
 1.Add
 2.Multiplication
2

 Multiplication c1 * c2:
 The complex no is:0+20i
Enter choice[Y/N]:N
*/





