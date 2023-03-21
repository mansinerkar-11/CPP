/*Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be 
unique. Standard Operations: Insert(key, value), Find(key), Delete(key)*/
#include<iostream>
#define MAX 26
using namespace std;

struct node
{
	string word;
	string meaning;			//Creating the node 
	
	node *next;
};
//End of struct node
class Hashtable
{
	node *ht[MAX];
	public:
		Hashtable()
			{
				for(int i=0;i<26;i++)
					{
						ht[i]=new node;
						ht[i]->next=NULL;
					}
			}
			int hash(string key);
			void insert(string w,string m);
			int find(string w);
			int delete1(string w);
			void display();
};
//End of class hashtable.
int Hashtable::hash(string key)
{
	int x;
	x=tolower(key[0])-97;		//Hash function
	return x;
}
void Hashtable::insert(string w,string m)
{
	int pos;
	pos=hash(w);
	node *current;
	current = new node;
	current->word=w;		//Insert function
	current->meaning=m;
	current->next=ht[pos]->next;
	ht[pos]->next=current;
}
int Hashtable::find(string w)
{
	int pos,count=1;
	node *current;
	pos = hash(w);
	current = ht[pos]->next;	//Find function
	
	while(current != NULL)
		{
			if(current->word == w)
				{
				    cout<<"Word "<<w<<" found at position:"<<pos<<endl;
					cout<<"Meaning of the word:"<<(current->meaning)<<endl;
					cout<<"No. of comparisons:"<<count<<endl;
					return 0;
				}
				count++;
				current = current->next;
		}
		cout<<"Word "<<w<<" not found in dictionary."<<endl;
		return 0;
}
int Hashtable::delete1(string w)
{
    int pos;
    pos = hash(w);
    node* head;
    head = ht[pos];
    if(head==NULL)
    {
        return -1;
    }
    else if(head!=NULL)			//Delete function.
    {
        if(head->word==w)
        {
            head = head->next;
            return 1;
        }
        else
        {
            node* temp = NULL;
            node* prevptr = head;
            node* currentptr = head->next;
            while(currentptr != NULL)
            {
                if(currentptr->word==w)
                {
                    temp = currentptr;
                    currentptr = NULL;
                }
                else
                {
                    prevptr = prevptr->next;
                    currentptr = currentptr->next;
                }
            }
            if(temp != NULL)
            {
                prevptr->next=temp->next;
                return 1;
            }
            else
            {
                return -1;
            }

        }
    }
    return 0;
}
void Hashtable::display()
{
    for(int i=0;i<MAX;i++)
    {
        cout<<char(i+97)<<" : "<<endl;
        node *temp;
        temp = ht[i]->next;
        while(temp!=NULL)
        {
            cout<<"  "<<temp->word<<":"<<temp->meaning<<endl;		//Display function.
            temp = temp->next;
        }
    }
}
int main()
{
	Hashtable H;
	int choice;
	string word1,meaning1;
	while(true)
		{
			cout<<"***Choice Menu***"<<endl;
			cout<<"(1)Insert a word and its meaning."<<endl;
			cout<<"(2)Delete a word from the dictionary."<<endl;
			cout<<"(3)Find a word in the dictionary."<<endl;
            		cout<<"(4)Display whole content of the dictionary."<<endl;
			cout<<"(5)Exit the program."<<endl;
			cout<<"Enter your choice:"<<endl;
			cin>>choice;
		if(choice==1)
			{
				cout<<"Enter word to be inserted:"<<endl;
				cin>>word1;
				cout<<"Enter the meaning of the entered word:"<<endl;
				cin>>meaning1;
				H.insert(word1,meaning1);
			}
		else if(choice==2)
			{
                cout<<"Enter word to be deleted: "<<endl;
                cin>>word1;
                int delres=H.delete1(word1);
                if(delres==-1)
                {
                    cout<<"Can't delete! word "<<word1<<" not found in the dictionary."<<endl;
                }
                else if(delres==1)
                {
                    cout<<"Word "<<word1<<" deleted from the dictionary."<<endl;
                }
                
			}
		else if(choice==3)
			{
				cout<<"Enter word to be find: "<<endl;
				cin>>word1;
				H.find(word1);
				
			}
        	else if(choice==4)
            	{
                	H.display();
            	}
		
		else if(choice==5)
		{
			cout<<"Exiting the program..."<<endl;
			exit(0);
		}
		else
			{
				cout<<"Wrong choice entered. Enter correct choice again."<<endl;
			}
		}
}
