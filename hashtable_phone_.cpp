/*Prcatical 2
Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client's telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a
set of telephone numbers*/
#include<iostream>
#include<cstdlib>
#define MAX 10
using namespace std;

struct phonebook
{
	string name;
	long long int phone;
};

class Hash_table{
	phonebook hashtable[MAX];
public:
	Hash_table() {
		for(int i=0;i<MAX;i++)
			hashtable[i].phone=0;
	}
	void display() {
		cout<<"Hash Table\n";
		for(int i=0;i<MAX;i++)
			cout<<endl<<i<<" : "<<hashtable[i].name<<" , "<<hashtable[i].phone;
	}
	int hash(long long int key) {
		return (key%MAX);
	}

	
	bool add(phonebook p) {						//will return false only if hashtable is full already
		int i,pos;
		pos = hash(p.phone);
		if(hashtable[pos].phone==0) {
			hashtable[pos]=p;
			return true;						
		}
		else {
			for(i=(pos+1)%MAX;i!=pos;i = (i+1)%MAX) {
				if(hashtable[i].phone==0) {
					hashtable[i]=p;
					return true;
				}
			}
		return false;				//Overflow
		}
	}
	int search(long long int key) {
		int pos, count = 1;
		bool found = false;
		pos = hash(key);
		if(hashtable[pos].phone==key) {
			found = true;
			cout<<"\nNumber of Comparisions : "<<count;
			return pos;
		}
		else  {
			for(int i=(pos+1)%MAX;i!=pos;i=(i+1)%MAX) {
				count++;
				if(hashtable[i].phone==key) {
					found = true;
					cout<<"\nNumber of Comparisions : "<<count;
					return i;
				}
			}
		}
		cout<<"\nNumber of Comparisions : "<<count;					//if element not found it will come here 
		if(found==false) {											
			return -1;
		}
	}
	int remove(long long int key) {
		int pos;
		pos = search(key);
		if(pos>=0) {
			hashtable[pos].phone=0;
			hashtable[pos].name ="";
			return pos;	
		}
		return -1;		
		
	}
	bool add_quadratic(phonebook p) {		//will return false only if hashtable is full already
		int pos;
		for(int i=0;i<MAX;i++)
		{
			pos=(hash(p.phone)+i*i)%MAX;
			if(hashtable[pos].phone==0) {
				hashtable[pos]=p;
				return true;
			}
		}
		return false;		//Overflow
	}
	
	int search_quadratic(long long int key) {			
		int pos, count = 1;
		bool found = false;
		pos = hash(key);
		if(hashtable[pos].phone==key) {
			found = true;
			cout<<"\nNumber of Comparisions : "<<count;
			return pos;
		}
		else  {
			for(int i=1;i<MAX;i++) {
				count++;
				pos = (hash(key) + i*i)%MAX;
				if(hashtable[pos].phone==key) {
					found = true;
					cout<<"\nNumber of Comparisions : "<<count;
					return pos;
				}
			}
		}
		cout<<"\nNumber of Comparisions : "<<count;
		if(found==false) {									//if element not found it will come here
			return -1;										
		}
	}
	int remove_quadratic(long long int key) {		//it's completely similar to remove() made for linear probing
		int pos = search_quadratic(key);			//except for this line (it's pos = search(key) in linear probing)
		if(pos>=0) {
			hashtable[pos].phone=0;
			hashtable[pos].name ="";
			return pos;	
		}
		return -1;			
		
	}
};//end of class Hash_table
int main()
{
	phonebook p;
	Hash_table ht;
	int choice,x,probe_choice;
	bool slot_available;
	long long int val;
	cout<<"\t\tEnter 1 for Linear Probing"
		<<"\n\t\tEnter 2 for Quadratic Probing \n \tProbing Choice : ";
	cin>>probe_choice;
	system("clear");				//system("clear") in linux with #include<cstdlib> may be
	do {
	cout<<"\nHash Table Menu"
		<<"\n1. Add"
		<<"\n2. Search"
		<<"\n3. Remove"
		<<"\n4. Display"
		<<"\n5. Exit"
		<<"\nEnter Choice : ";	
	cin>>choice;
	switch(choice) {
		case 1:	cout<<"Enter Name and Phone Number to be added : ";
				cin>>p.name>>p.phone;
				if(probe_choice==1)
					slot_available=ht.add(p);					//Linear Probing
				else	
					slot_available=ht.add_quadratic(p);			//Quadratic Probing
				
				if(slot_available)
					cout<<"\nKey Added Sucessfully";
				else
					cout<<"\nHashtable Overflow";
				
				
				break;
				
		case 2:	cout<<"Enter value to be searched : ";
				cin>>val;
				if(probe_choice==1)					//Linear Probing
					x = ht.search(val);
				else								//Quadratic Probing
					x = ht.search_quadratic(val);	
				
				if(x!=-1)
					cout<<endl<<val<<" found at Pos = "<<x;
				else
					cout<<"\nNot Found";
				break;
		
		case 3: cout<<"Enter value to be removed : ";
				cin>>val;
				if(probe_choice==1)					//Linear Probing
					x = ht.remove(val);
				else
					x = ht.remove_quadratic(val);	//Quadratic Probing
					
				if(x!=-1)
					cout<<endl<<val<<" removed from Pos = "<<x;
				else
					cout<<"\nNot Found";
				break;
		
		case 4: ht.display();
				break;		
				
		case 5:	break;
		
		default: cout<<"\nInvalid Choice";
	}
    }while(choice!=5);
	
	return 0;
}

