
//Name: Mansi Dinesh Nerkar        Div:B     Roll no: 77#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int rollnum;
	char name[30];
	char address[50];
	
	ofstream outf("Detail.txt");
	cout<<"Enter roll number:"<<endl;
	cin>>rollnum;
	
	cout<<"Enter Name:"<<endl;
	cin.ignore();
	cin.getline(name,30);
	
	cout<<"Enter address:"<<endl;
	cin.ignore();
	cin.getline(address,50);
	
	outf<<rollnum<<endl;
	outf<<name<<endl;
	outf<<address<<endl;
	outf.close();	
	ifstream inf;
	inf.open("Details.txt");
	inf>>rollnum;
	inf>>name;
	inf>>address;
	cout<<"\nRoll number:"<<rollnum<<"\nName:"<<name<<"\nAddress:"<<address;
	
	fstream appfile;
	appfile.open("Detail.txt",ios::in | ios::app);
	cout<<"\nEnter name:"<<endl;
	cin.getline(name,30);
	appfile.write(name,30);
	appfile.close();
	ifstream fin("Detail.txt");
	char ch;
	while(!fin.eof())
	{
		ch=fin.get();
		cout<<ch;
	}
	
	return 0;

}

/*
Enter roll number:
56
Enter Name:
prajwal
Enter address:
sadasda asdasd sa

Roll number:56
Name:prajwal
Address:adasda asdasd sa
Enter name:
prajwal
56
prajwal
adasda asdasd sa
prajwal
*/
