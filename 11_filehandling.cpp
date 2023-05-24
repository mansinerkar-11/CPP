
#include<iostream>
#include<fstream>
using namespace std;

struct student {
	int rollno;
	char name[20];
	void getdata() {
		cout<<"Enter roll no and name ";
		cin>>rollno>>name;
	}
	void putdata() {
		cout<<rollno<<" "<<name;
	}
}; //end of student

class File {
	fstream fp;
	student s;
	public :
		void create();
		void display();
		void append();
		void search();
		void physicaldelete();
		void logicaldelete();
};
void File::create()
{
	char ans;
	fp.open("student.dat",ios::out);
	do {
		s.getdata();
		fp.write((char*)&s,sizeof(s));
		cout<<"Do you want to add more records (y/n) : ";
		cin>>ans;
	}while(ans=='y');

	fp.close();
}
void File::display()
{
	fp.open("student.dat",ios::in);
	while(!fp.eof()) {
		fp.read((char*)&s,sizeof(s));
		if(!fp.eof())
			if(s.rollno!=0) {
				s.putdata();
				cout<<endl;
			}
	}
	fp.close();
}
void File:: append() {
	char ans;
	fp.open("student.dat",ios::app);
	do{
		s.getdata();
		//read record in memory
		fp.write((char*)&s,sizeof(s));
		//write record to file
		cout <<"\n Add more?";
		cin>> ans;
	}while(ans=='y');
	fp.close();
}
void File::search() {
	fp.open("student.dat",ios::in); int r;
	cout << "\n Enter roll to be searched :";
	cin >> r;
	while (!fp.eof()){
		fp.read((char*)&s,sizeof(s));
		//read record from file
		if (!fp.eof() and s.rollno==r) {
			s.putdata();
			//display record on screen
			break;
		}
	}
	fp.close();
}
void File::physicaldelete() {
	int r;
	fstream tfp;// temporary file
	fp.open("student.dat",ios::in);
	tfp.open("temp.dat",ios::out);
	cout << "\n Enter roll to be deleted :";
	cin >> r;
	while (fp.read((char*)&s,sizeof(s))){
		//read record from student file
		if (s.rollno==r){
			cout << "\n Deleting .....\n";
			s.putdata();
			//display record on screen
		}
		else{
			tfp.write((char*)&s,sizeof(s));
			//write record to temp file
		}
	}// end of while
	fp.close();
	tfp.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
}
void File:: logicaldelete(){
	int r;
	//open read as well as write mode
	fp.open("student.dat",ios::in|ios::out);
	cout << "\n Enter roll to be logically deleted :";
	cin >> r;
	while (fp.read((char*)&s,sizeof(s))){
	//read record from student file
		if (s.rollno==r){
			cout << "\n Deleting .....\n";
			s.rollno=0;
			// move pointer to previous record
			fp.seekp(-1*sizeof(s),ios::cur);
			fp.write((char*)&s,sizeof(s)); //rewrite the record
			break;
		}
	}// end of update
	fp.close();
}
int main()
{
	File F1;
	int choice;
	do {
		cout<<"\n1.Create"
			<<"\n2.Display"
			<<"\n3.Append"
			<<"\n4.Search"
			<<"\n5.Physical Delete"
			<<"\n6.Logical Delete"
			<<"\n7.Exit"
			<<"\nEnter Choice";
		cin>>choice;
		switch(choice) {
			case 1:
				F1.create();
				break;
			case 2:
				F1.display();
				break;
			case 3:
				F1.append();
				break;
			case 4:
				F1.search();
				break;
			case 5:
				F1.physicaldelete();
				break;
			case 6:
				F1.logicaldelete();
				break;
			case 7:
				break;
			default:
				cout<<"\nInvalid Choice";
		}
	}while(choice!=7);
	return 0;
}
