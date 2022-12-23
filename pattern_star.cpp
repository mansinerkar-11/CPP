#include<iostream>
using namespace std;

int main()
{
    /*
    --Program to draw below pattern
    * 
    * * 
    * * * 
    * * * * 
    -end-
    */
   cout<<"\n";
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i>=j)
            {
                cout<<"* ";
            }
            
        }
        cout<<endl;
    }


    cout<<"\n\n______________________________________________________\n\n";
    /*
    --Program to draw 
     
     * * * * 
      * * * 
       * * 
        * 
    ---end--

    */
    for(int m=0; m<4; m++)
    {
        for(int n=0; n<4; n++)
        {
            if(m>n)
            {
                cout<<" ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }

    cout<<"\n\n______________________________________________________\n\n";
    /*
    --Program to draw the following pattern
        
*    
* *   
* * *  
* * * * 
 * * * 
  * * 
   * 
   
   --end--
    
    */
    for(int y=0; y<4; y++)
    {
        for(int z=0; z<4; z++)
        {
            if(y+z>=3)
            {
                cout<<"* ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
   for(int a=0; a<4; a++)
    {
        for(int b=0; b<4; b++)
        {
            if(a>b)
            {
                cout<<" ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }


    return 0;
}