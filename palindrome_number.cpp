//program to check the number is palindrome or not.
 #include<iostream>
 using namespace std;
 int main()
 {
    int r=0, num, rev, temp;
     cout<<"Enter numebr: ";
     cin>>num;
     temp = num;
     while (num>0)
     {
        rev = num % 10;
        num = num / 10;
        r = r*10 + rev;
     }
     if (r == temp)
     {
        cout<<"It is palindrome"<<endl;
        
     }
     else
     {
        cout<<"It is not a palindrome"<<endl;
     }
   
     
     return 0;
 }