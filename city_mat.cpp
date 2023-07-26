/*There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight take
to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.*/


#include <iostream>
#include <string.h>
#define size 20
using namespace std;

class adj_matrix
{
	int t_arr[size][size];
	int f_arr[size][size];
	string cities[size];
	int n;
	public:
	adj_matrix(int count)
	{
		n = count;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				t_arr[i][j] = 0;
				f_arr[i][j] = 0;
			}
		}
	}
	void getcities();
	void display(char ch);
	void get_data(char ch);
	void search_flight();
};
void adj_matrix :: getcities()
{
	
	for(int i=0;i<n;i++)
	{
		cout<<"ENTER NAME OF CITY"<<i<<":"<<endl;
		cin>>cities[i];
	}
}
void adj_matrix :: display(char ch)
{
	if(ch == 'T')
	{
		for(int i = 0;i<n;i++)
	{	
		cout<<"\n";
		for(int j = 0;j<n;j++)
		{
			cout<< t_arr[i][j]<<"\t";
		}
	}
	}
	else if(ch == 'F')
	{
		for(int i = 0;i<n;i++)
		{	
			cout<<"\n";
			for(int j = 0;j<n;j++)
			{
				cout<< f_arr[i][j]<<"\t";
			}
		}
	}
	else if(ch == 'C') 
	{
		for(int i = 0;i<n;i++)
		{	
			cout<<cities[i]<<endl;
		}
	}
}
void adj_matrix :: get_data(char ch)
{
	if(ch == 'T')
	{
		for(int i = 0;i<n;i++)
		{	
			for(int j = 0;j<n;j++)
			{
				cout<<"ENTER TIME REQUIRED FROM"<<cities[i]<<"\tTO\t"<< cities[j]<<endl;
				cin>>t_arr[i][j];
			}
		}
	}
	else if(ch == 'F')
	{
		for(int i = 0;i<n;i++)
		{	
			
			for(int j = 0;j<n;j++)
			{
				cout<<"ENTER FUEL REQUIRED FROM\t"<<cities[i]<<"\tTO\t"<< cities[j]<<": ";
				cin>>f_arr[i][j];
			}
		}
	}
}

void adj_matrix :: search_flight()
{
	cout<<"WE CURRENTLY FLY TO THESE CITIES"<<endl;
	display('C');
	int ind1,ind2;
	string src,dest;
	cout<<"Enter source city"<<endl;
	cin>>src;
	cout<<"Enter destination city"<<endl;
	cin>>dest;
	for(int i = 0;i<n;i++)
	{
		if(cities[i] == src)
		{
			ind1 = i;
		}
		if(cities[i] == dest)
		{
			ind2 = i;
		}
	}
	if(t_arr[ind1][ind2]!= 0 && f_arr[ind1][ind2]!= 0)
	{
		cout<<"DIRECT FLIGHT EXISTS!!!!"<<endl;
		cout<<"\n";
		cout<<"TIME REQUIRED :"<<t_arr[ind1][ind2]<<endl;
		cout<<"\n";
		cout<<"FUEL REQUIRED :"<<f_arr[ind1][ind2]<<endl;
	}
	else
	{
		cout<<"DIRECT FLIGHT DOES NOT EXIST"<<endl;
	}
}



int main()
{
	int n,ch;
	char ch1 = 'Y';
	cout<<"Enter number of cities: ";
	cin>>n;
	adj_matrix a(n);
	a.getcities();
	do
	{
		cout<< "\t\t MENU"<<endl;
		cout<<"Enter 1 for displaying fuel chart"<<endl;
		cout<<"Enter 2 for displaying time chart"<<endl;
		cout<<"Enter 3 for inserting fuel chart data"<<endl;
		cout<<"Enter 4 for inserting time chart data"<<endl;
		cout<<"Enter 5 to display all cities"<<endl;
		cout<<"Enter 6 to search flight"<<endl;
		cout<<"\n";
		cout<<"Enter choice no."<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				a.display('F');
				break;
			case 2:
				a.display('T');
				break;
			case 3:
				a.get_data('F');
				break;
			case 4:
				a.get_data('T');
				break;
			case 5:
				a.display('C');
				break;
			case 6:
				a.search_flight();
				break;
		}
		cout<<"\n";
		cout<<"Do you wish to continue?(Y/N)"<<endl;
		cin>>ch1;
	}while(ch1 == 'Y');
	
	
	return 0;
}













