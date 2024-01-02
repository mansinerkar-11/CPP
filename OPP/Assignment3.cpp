//Name: Mansi Dinesh Nerkar        Div:B     Roll no: 77
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class publication
{
	protected:	
		
		float price;
		string name;
	public:
		virtual void display()=0;
		virtual void getdata()=0;
};
class booK: public virtual publication
{
	int pgcount;
	public:
		void getdata()
		{
			cout<<"Enter Book Title:";
	  	 	cin>>name;
			cout<<"Enter Book Price:";
			cin>>price;
			try
			{
				if(price>1000)
				{
					cout<<"Book Price is not affordable"<<endl;
					throw(price);
				}
				}
				catch(float)
				{cout<<"Enter Book Price:";
				cin>>price;
				}
			cout<<"Enter Page count:";
			cin>>pgcount;
			}
		void display()
		{	cout<<"\t\t\tBOOK\n";
			cout<<"\n\t\t\tBook Title is:"<<name;
			cout<<"\n\t\t\tBook Price is:"<<price;
			cout<<"\n\t\t\tPage Count is:"<<pgcount<<endl;
		}
};
class tape: public virtual publication
	{
		float playtime;
		public:
			void getdata()
			{
				cout<<"Enter Audiobook Title:";
				cin>>name;
				cout<<"Enter Audiobook Price:";
				cin>>price;
				try
				{
					if(price>1000)
					{
						cout<<"Audiobook is not affordable";
						throw(price);
					}
				}
				catch(float)
				{
					cout<<"Enter Affordabl price:";
					cin>>price;
					}
					cout<<"Enter Audiobook playtime:";
					cin>>playtime;
			}
			void display()
			{	cout<<"\t\t\tAUDIOBOOK";
				cout<<"\n\t\t\tAudiobook Title is:"<<name;
				cout<<"\n\t\t\tAudiobook Price is:"<<price;
				cout<<"\n\t\t\tAudiobook playtime:"<<playtime;
				}
	};

int main()
{	publication *p[50];
	int i=0,j;
	int choice;
	do
	{
	
	cout<<"\nEnter ur choice:\n1.Book \n2.Audiobook \n3.Details \n4.Exit"<<endl;
	cin>>choice;
	switch(choice)
	{	
		case 1:	cout<<"BOOK\n";
			p[i]=new booK();  //memory allocated
			p[i]->getdata();
			i++;
			break;
		case 2:
			p[i]=new tape();
			p[i]->getdata();
			i++;
			break;
		case 3:
			int n=i;
			for(int j=0;j<n;j++)
			{
				p[j]->display();
			}
			break;
		//default:
		//	cout<<"END OF PROGRAM";
		//	break;
		}
		}while(choice>=1 && choice<4);	
return 0;

}
	
	/*
    Enter ur choice:
1.Book 
2.Audiobook 
3.Details 
4.Exit
1
BOOK
Enter Book Title:Amazon 
Enter Book Price:222
Enter Page count:67

Enter ur choice:
1.Book
2.Audiobook
3.Details
4.Exit
2
Enter Audiobook Title:Amazonplay
Enter Audiobook Price:999
Enter Audiobook playtime:11 

Enter ur choice:
1.Book
2.Audiobook
3.Details
4.Exit
3
                        BOOK

                        Book Title is:Amazon
                        Book Price is:222
                        Page Count is:67
                        AUDIOBOOK
                        Audiobook Title is:Amazonplay
                        Audiobook Price is:999
                        Audiobook playtime:11
Enter ur choice:
1.Book
2.Audiobook
3.Details
4.Exit
4
*/
	
	
	
	
	
	
	
	
	
		
		 
