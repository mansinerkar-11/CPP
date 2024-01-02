
//Name: Mansi Dinesh Nerkar        Div:B     Roll no: 77#include<iostream>
#include<cmath>
using namespace std;
template <class T>

class sort
{
	public:
	T data[100],temp;
	int n,idx;
	void inputing();
	void displaying();
	void selectionsort();

};


template <class T>
void sort<T> :: inputing()
{	
	
	cout<<"Enter number of elements :";
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		cout<<"Enter "<<i+1<<" element";
		cin>>data[i];
	}
}


template <class T>
void sort<T> :: displaying()
{	
	
	for(int i=0;i<n;i++)
	{	
		cout<<" "<<data[i];
	}
}

template <class T>
void sort<T> :: selectionsort()
{
	for(int i=0;i<n;i++)
	{
		idx=i;
		for(int j=i;j<n;j++)
		{
			if(data[idx]>data[j])
			{
				idx=j;
			}
			
		}
		temp=data[idx];
		data[idx]=data[i];
		data[i]=temp;

}
}
int main()
{	sort <int> it;
	sort <float> flt;
	sort <char> chr;
	sort <string> str[30];
	char ask;
	int option;
	do
	{
	cout<<"1.Integer Operations\n 2.Float Operations\n 3.Character Operations\n 4.String Operations\n5.Exit\n";
	cin>>option;
	switch(option)
	{
	case 1:
		cout<<"Integer type\n";
		it.inputing();
		it.displaying();
		cout<<"\n";
		it.selectionsort();
		it.displaying();
		break;
	case 2:
		cout<<"\nFloat type\n";
		flt.inputing();
		flt.displaying();
		cout<<"\n";
		flt.selectionsort();
		flt.displaying();
		break;
	case 3:
		cout<<"\nChar type\n";
		chr.inputing();
		chr.displaying();
		cout<<"\n";
		chr.selectionsort();
		chr.displaying();
		break;
	case 4:
		cout<<"String type\n";
		int i,leng;
		cout<<"Enter the length of string:";
		cin>>leng;
		str[i].inputing();
		str[i].displaying();
		cout<<"\n";
		for(i=0;i<leng;i++)
		{
		str[i].selectionsort();
		str[i].displaying();
		}
		break;
	default:
		break;
	}
	cout<<"\nWant to repeat:";
	cin>>ask;
	}while(ask=='y' || ask=='Y');
		
	return 0;
}


/*
Outputs:
1.Integer Operations
 2.Float Operations
 3.Character Operations
 4.String Operations
5.Exit
1
Integer type
Enter number of elements :5
Enter 1 element50   
Enter 2 element20
Enter 3 element30
Enter 4 element10
Enter 5 element40
 50 20 30 10 40
 10 20 30 40 50
 Want to repeat:Y
 1.Integer Operations
 2.Float Operations
 3.Character Operations
 4.String Operations
5.Exit
2

Float type
Enter number of elements :5 
Enter 1 element39.2
Enter 2 element22.5
Enter 3 element11.9
Enter 4 element99.1
Enter 5 element33.2
 39.2 22.5 11.9 99.1 33.2
 11.9 22.5 33.2 39.2 99.1
Want to repeat:N
 */
