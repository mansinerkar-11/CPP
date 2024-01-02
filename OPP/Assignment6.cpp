
//Name: Mansi Dinesh Nerkar        Div:B     Roll no: 77
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Item
{
    public:
    char name[20];
    int quantity;
    int cost;
    int code;
    bool operator==(const Item &i1)
    {
        if(code==i1.code)
            return 1;
        else
            return 0;
    }
    bool operator<(Item &i1)
    {
    if(code<i1.code)
        return 1;
    else
    return 0;
    }
};
vector<Item>v1;
void print(Item &i1);
void display();
void search();
void insert();
void dlt();
int main()
{
    int ch;
    do
    {
        cout<<"\n\t\t   *MENU*\t\t\n"<<endl;
        cout<<"\t\t 1.Insert\n\t\t 2.Display\n\t\t 3.Search\n\t\t 4.Sort\n\t\t 5.Delete\n\t\t 6.Exit\n"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(v1.begin(),v1.end());
                cout<<"Sorted items are :";
                display();
                break;
            case 5:
                dlt();
                display();
                break;
            case 6:
                exit(0);
        }
               
    }while(ch!=7);
    return 0;
}
void insert()
{
        Item i1;
        cout<<"Enter the Name:";
        cin>>i1.name;
        cout<<"Enter the Quantity:";
        cin>>i1.quantity;
        cout<<"Enter cost: ";
        cin>>i1.cost;
        cout<<"Enter code: ";
        cin>>i1.code;
        v1.push_back(i1);
}
void display()
{	cout<<"\n---------------------------\n";
        for_each(v1.begin(),v1.end(),print);
        cout<<"\n---------------------------\n";
}
void print(Item &i1)
{
        cout<<"\nName: "<<i1.name;
        cout<<"\nQuantity: "<<i1.quantity;
        cout<<"\nCost: "<<i1.cost;
        cout<<"\nCode: "<<i1.code;
}
void search()
{
        vector<Item>::iterator a;
        Item i1;
        cout<<"\nEnter Item code to be search: ";
        cin>>i1.code;
        a=find(v1.begin(),v1.end(),i1);
        if(a!=v1.end())
            cout<<"Item code is Found";
        else
            cout<<"Not Found";
}
void dlt()
{
        vector<Item>::iterator a;
        Item i1;
        cout<<"\nEnter Item code to be deleted: ";
        cin>>i1.code;
        a=find(v1.begin(),v1.end(),i1);
        if(a!=v1.end())
        {
            v1.erase(a);
            cout<<"Item deleted";
        }
        else
        {
            cout<<"\nNot fount";
        }
}


// OUTPUT
/* *MENU* 

                 1.Insert 
                 2.Display
                 3.Search 
                 4.Sort   
                 5.Delete 
                 6.Exit   

Enter your choice:1       
Enter the Name:abc
Enter the Quantity:1
Enter cost: 1
Enter code: 5

                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:2

---------------------------

Name: abc
Quantity: 1
Cost: 1
Code: 5
---------------------------

                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:3

Enter Item code to be search: 5
Item code is Found
                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:5

Enter Item code to be deleted: 5
Item deleted
---------------------------

---------------------------

                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:1
Enter the Name:a
Enter the Quantity:1
Enter cost: 1
Enter code: 1

                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:1
Enter the Name:v
Enter the Quantity:5
Enter cost: 3
Enter code: 8

                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:4
Sorted items are :
---------------------------

Name: a
Quantity: 1
Cost: 1
Code: 1
Name: v
Quantity: 5
Cost: 3
Code: 8
---------------------------

                   *MENU*

                 1.Insert
                 2.Display
                 3.Search
                 4.Sort
                 5.Delete
                 6.Exit

Enter your choice:6*/
