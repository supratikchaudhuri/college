
#include<iostream>
using namespace std ;
template<class T,int size>     //Using class template
class stack
{
        T s[size] ;
        int top ;
        public :
        stack()
        {
                top = -1 ;
        }
        void push(T data)         // push() to add elements to a stack
        {
                if (top == size)
                {
                        cout << "Stack is full" << endl ;
                }
                else
                {
                        top++ ;
                        s[top] = data ;
                }
        }
        T pop()             // pop() to remove the first element of the stack
        {
                T data ;
                if (top == -1)
                {
                        cout << "Stack is empty" << endl ;
                }
                else
                {
                        data = s[top] ;
                        top-- ;
                        return data ;
                }
        }
        void display()
        {
                
                for(int i=top; i>=0 ; i--)
                {
                        cout << s[i] << "\t" ;
                }
                
        }
};
int main()
{
        stack <int,5> s1;
        int n=0 , e =0 ;
        while(n!=4)
        {
                cout << "\nWhat would you like to \n\n 1.Push element \n 2.Pop element \n 3.Display element \n 4.Exit \n\n " ;
                cin >> n;
                switch(n)
                {
                        case 1:
                        {
                                cout << "Enter element: " ;
                                cin >> e ;
                                s1.push(e) ;
                        }
                        break ;
                        case 2:
                        {
                                s1.pop() ;
                        }
                        break ;
                        case 3:
                        {
                                s1.display() ;
                        }
                        break ;
                        case 4:
                        {       
                                cout << "Program exit\n" ;
                        }
                        break ;
                        default : 
                        {
                                cout << "Please enter a valid option " ;
                        }
                        break ;
                }
       }
       return 0 ;
}                            
/* 
Output :
What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 1
Enter element: 3

What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 1
Enter element: 5

What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 1
Enter element: 7

What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 1
Enter element: 8

What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 3
8	7	5	3	
What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 2

What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 3
7	5	3	
What would you like to 

 1.Push element 
 2.Pop element 
 3.Display element 
 4.Exit 

 4
Program exit
	
*/
