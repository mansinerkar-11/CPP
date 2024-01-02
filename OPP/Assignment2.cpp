//Name: Mansi Dinesh Nerkar        Div:B     Roll no: 77
#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
#define max_len 25
using namespace std;
class student
{
public:
	int Roll_no;
	char Name[30];
	int srno;
	char Cls[7];
	char Div[3];
	char DOB[10];
	char bldgrp[5];
	long int Contact;
	static int count; //Static data variable
	void getdata();
	friend void display(student & obj);

	student()		//constructor
      { 
		Roll_no:0;
		Roll_no=count;
		count++;
      }
	~student()		//destructor
      {
		count++;
      }
	static void getcount()	//static member fuction
	{
		cout<<"\n count"<<count;
	}
	student(int Roll_no)  //parameterized constructor
	{
		this->Roll_no=Roll_no;
	}
	student(student & obj) // Copy constructor
	{
		Roll_no=obj.Roll_no;
		strcpy(Name,obj.Name);
		strcpy(Cls,obj.Cls);
		strcpy(Div,obj.Div);
		strcpy(DOB,obj.DOB);
		strcpy(bldgrp,obj.bldgrp);
		Contact=obj.Contact;
		srno=count;
		count++;
	}
};	//end of class	

	int student::count=0;//static variable default declaration
	void student::getdata()
{
	cout<<"\nEnter Name:";
	cin>>Name;
	cout<<"\nEnter Roll No:";
	cin>>Roll_no;
	cout<<"\nEnter class :";
	cin>>Cls;
	cout<<"\nEnter Div:";
	cin>>Div;
	cout<<"\nEnter Date Of Birth:";
	cin>>DOB;
	cout<<"\nEnter Blood group:";
	cin>>bldgrp;
	cout<<"\nEnter Contact No:";
	cin>>Contact;
}
	void display(student & obj) //friend Fuction
{
	cout<<"\n"<<obj.Roll_no;
	cout<<"\t"<<obj.Name;
	cout<<"\t"<<obj.Cls;
	cout<<"\t"<<obj.Div;
	cout<<"\t"<<obj.DOB;
	cout<<"\t"<<obj.Contact;
	cout<<"\t\t"<<obj.bldgrp<<endl;
}

int main()
{
	student s1;
	student s2(s1);  //copy constructor
	//cout<<"\n Enter Data for 1st Student:"<<"\n";
	//s1.getdata();
	//cout<<"All the details are as below:";
	student *s[50];	//array of object
	int i,n;
	cout<<"\n How many student objects do you want to create?";
	cin>>n;
	
	for (i=0;i<n;i++)
	{	
		s[i]=new student(); //dynamic memory allocation operator
	}
	
	for(i=0;i<n;i++)
	{
		s[i]-> getdata();
	}
	cout<<"\n-----------------------------------------------------------------";
	cout<<"\nRoll no\tName \tClass \tDiv \tDOB \tContact \tBlood Grp\n";
	cout<<"\n-----------------------------------------------------------------";
	//display(s1);
	for (i=0;i<n;i++)
	{
		display(*s[i]);
	}
	for (i=0;i<n;i++)
	{
		delete (s[i]); //dynamic memory de-allocation operator
	}
return 0 ;
}

/*
 How many student objects do you want to create?2

Enter Name:prajwal

Enter Roll No:54

Enter class :SE

Enter Div:B

Enter Date Of Birth:16052002

Enter Blood group:A+

Enter Contact No:971312311

Enter Name:siddhart

Enter Roll No:53

Enter class :SE

Enter Div:B

Enter Date Of Birth:16052002

Enter Blood group:O+

Enter Contact No:9724312131 

-----------------------------------------------------------------
Roll no Name    Class   Div     DOB     Contact         Blood Grp

-----------------------------------------------------------------
54      prajwal SE      B       16052002        971312311               A+

53      siddhart        SE      B       16052002        2147483647              O+

*/
