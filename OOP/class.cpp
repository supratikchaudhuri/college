/*Supratik CHaudhuri
Div-A
Roll no.- PA49
*/
#include <iostream>
using namespace std;
class student
{
private:
	char name[5]; char address[5]; int year[5]; char Bgrp[5];
	int roll; int division; int phone;
public:
	student()
	{
		cout<< "im a constructor";
	}
	~student()
	{	
		cout<<" im a destructor";
	
	}
	void read();
	void display();
};
void student :: read()
{	
	cout<< "\nenter roll no.";
	cin>> roll;
	cout<< "\nName- ";
	cin>> name;
	cout<< " \nenter year- ";
	cin>> year;
	cout<< "\nEnter division";
	cin>> division;
	cout<< "\naddress-";
	cin>> address;
	cout<< " \nBgrp- ";
	cin>> Bgrp;
}
void student :: display()
{
	cout<<"\n Roll no-"<<roll;
	cout<<"\n Name- "<<name;
	cout<<"\n year- "<<year;
	cout<<"\n Division- "<<division;
	cout<<"\n Address- "<<address;
	cout<<"\n Blood Group- "<<Bgrp;
}
int main()
{
	student s;
	s.read();
	s.display();
	return 0;

}
/*OUTPUT
im a constructor
Roll no 57
Name- SAM
year- 2
Division- 3
Blood Group- A
im a destructor
*/	
