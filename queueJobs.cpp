/* Write C++ program for simulating job queue. Write functions to add job and delete job from queue.  */

#include<iostream>
using namespace std;
int queue[10], size_queue = 10, front = - 1,position_element = - 1;

//To insert elements in queue
void Insert() 
{
   int element;
   if (position_element == size_queue - 1)
   {
      cout<<"Queue Overflow"<<endl;
   }

   else 
   {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : ";
      cin>>element;
      position_element++;
      queue[position_element] = element;
   }
}

//To Delete element from queue
void Delete() 
{
   if (front == - 1 || front >position_element) 
   {
      cout<<"Queue Underflow ";
      return ;
   } 
   else 
   {
      cout<<"Element deleted from queue is : "<< queue[front];
      front++;;
   }
}

//To display elements of queue
void Display() {
   if (front == - 1) 
   {
      cout<<"Queue is empty"<<endl;
   }
   else 
   {
      cout<<"Queue elements are : ";
      for (int i = front; i <=position_element; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}

int main() 
{
   int choice;
   cout<<"1) Insert element in queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do 
   {
      cout<<"Enter your choice : ";
      cin>>choice;
      switch (choice) 
      {
         case 1: Insert();
         break;
         case 2: Delete();
         break;
         case 3: Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(choice!=4);
   return 0;
}