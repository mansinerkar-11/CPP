#include<iostream>
using namespace std;
class student
{
    private:
        string name ;
    
    public:
    void getdata(void)
    {
        string std_name;
        cout<<"Enter name: ";
        name=std_name;
    }
    void putdata(void)
    {
        cout<<"Student name: "<<name;
    }

};

class school:public student
{
    private:
        int roll;
    public:
    void getdata(void)
    {
        student::getdata();
        cout<<"Enter roll number: ";
        cin>>roll;
    

    }
    void putdata(void)
    {
        student::putdata();
        cout<<"Roll number: "<<roll;
    }   
};

class clg:public student
{
    private:
        int seat_no;
    public:
    void getdata(void)
    {
         student::getdata();
        cout<<"Enter seat number: ";
        cin>>seat_no;

    }
    void putdata(void)
    {
        student::putdata();
        cout<<"Roll number: "<<seat_no;
    }   

};

int main()
{
    school sc;
    clg c;
    sc.getdata();
    c.getdata();
    sc.putdata();
    c.putdata();

  
    return 0;
}

