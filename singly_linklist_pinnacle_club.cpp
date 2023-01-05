// Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, 
// third and final year of department can be granted membership on request. Similarly one may 
// cancel the membership of club. First node is reserved for president of club and last node is 
// reserved for secretary of club. Write C++ program to maintain club member‘s information using 
// singly linked list. Store student PRN and Name. Write functions to:
// a)	Add and delete the members as well as president or even secretary.
// b)	Compute total number of members of club
// c)	Display members
// d)	Two linked lists exists for two divisions. Concatenate two lists 

#include<iostream>
using namespace std;
class node
{
    public:
        string name,prn;
node *next;
};
class Pinnacle
{
    public:
    node *q;
    void add_prez();
    void add_mem();
    node *new_mem;
    node *president=NULL;
    node *temp;
    node *sec = NULL;
};
void Pinnacle :: add_prez()
{
    string prez_prn,prez_name,sec_prn,sec_name;
    cout<<"Enter president's name:"<<endl;
    cin>>prez_name;
    cout<<"Enter president's prn:"<<endl;
    cin>>prez_prn;
    cout<<"Enter secratary's name:"<<endl;
    cin>>sec_name;
    cout<<"Enter secratary's prn:"<<endl;
    cin>>sec_prn;
    president = new node();
    sec = new node();
    president-> prn = prez_prn;
    president-> name = prez_name;
    president-> next = sec;
    sec-> prn = sec_prn;
    sec-> name = sec_name;
sec-> next = NULL;
}
void Pinnacle::add_mem()
{
    int count=0,pos,i;
    for(q=president;q!=NULL;q=q->next)
    {
count+=1; }
    cout<<"Enter position to add member:"<<endl;
    cin>>pos;
    if(pos>0 && pos<=count)
    {
        new_mem= new(node);
        cout<<"Enter PRN:"<<endl;
        cin>>new_mem->prn;
        cout<<"Enter Name:"<<endl;
        cin>>new_mem->name;
        q=president;
        for(i=1;i<pos-1;i++)
{
q=q->next;
        }
        new_mem->next=q->next;
        q->next=new_mem;
}
else
    {
        cout<<"INVALID POSITION"<<endl;
} }
int main() {
    Pinnacle p;
    p.add_prez();
    p.add_mem();
    return 0;
}








