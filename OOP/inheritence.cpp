#include<iostream>
using namespace std;
class employee //Base class
{
protected:
	int id;
	string fname,lname;
	double salary;
public:
virtual void accept(); //using virtual functions
virtual void display();
virtual double calculate()=0;// pure virtual function
};

void employee::accept()
{
	cout<<"Enter First Name: ";
	cin>>fname;
	cout<<"Enter Last Name: ";
	cin>>lname;
	cout<<"Enter id: ";
	cin>>id;
}

void employee::display()
{
	cout<<"\nEMPLOYEE DETAILS:\n\nName: "<<fname<<" "<<lname<<"\nID: "<<id<<"\nSalary: "<<salary<<"\n\n";
	
}

class s_employee:virtual public employee //derived class
{
protected:	double bsalary;
public:
	void accept()
	{
		
		cout<<"Base Salary: ";
		cin>>bsalary;
	}
	double calculate()
	{
		salary=bsalary;
		return salary;
	}
};

class h_employee:public employee //derived class
{
	int hrs;
public:
	void accept()
	{
		
		cout<<"Hours of work: ";
		cin>>hrs;
	}
	double calculate()
	{
		if (hrs<=40)
		{
			salary=hrs*500;
		}
		else
		{
			salary=(hrs-40)*1000+40*500;
		}
	}
};

class c_employee:virtual public employee //derived class
{
protected: int sales;
public: 
	void accept()
	{
		
		cout<<"PerCent Sales: ";
		cin>>sales;
	}
	double calculate()
	{
		salary=sales*1200;
		return salary;
	}
};

class sc_employee:public s_employee, public c_employee // super child class of s_employee and c_employee
{
	
public:
	void accept()
	{
		s_employee::accept();
		c_employee::accept();
		
	}
	
	
	
	double calculate()
	{
	salary=bsalary+(sales*1000);
	return salary;
	}
};

int main()
{	
	int n; //declaring variable
	employee *p; //declaring pointer of return type class
	cout<<"EMPLOYER'S DESK\n\n";
	n=0;
	while(n!=5)
	{
		cout<<"Enter Employee to add:\n1)Salaried Employee\n2)Hourly Employee\n3)Commissioned Employee\n4)Salaried Commissioned Employee\n5)Exit\n\n";
		cin>>n;
		switch(n)
		{
		case 1:
			{
				s_employee s; // object creation
				p=&s;
				p->employee::accept(); // calling functions by reference
				p->accept();
				p->calculate();
				p->display();
			}
		break;
		case 2:
			{
				h_employee h; // object creation
				p=&h;
				p->employee::accept(); // calling functions by reference
				p->accept();
				p->calculate();
				p->display();
			}
		break;
		case 3:
			{
				c_employee c; // object creation
				p=&c;
				p->employee::accept(); // calling functions by reference
				p->accept();
				p->calculate();
				p->display();
			}
		break;
		case 4:
			{
				sc_employee sc; // object creation
				p=&sc;
				p->employee::accept(); // calling functions by reference
				p->accept();
				p->calculate();
				p->display();
			}
		case 5:cout<<"Thank you for using\n\n";
		break;
		break;
		default: cout<<"Enter Valid Option\n\n";
		break;	
		}
	}
	
	return 0;
	
}
/*
OUTPUT:
EMPLOYER'S DESK

Enter Employee to add:
1)Salaried Employee
2)Hourly Employee
3)Commissioned Employee
4)Salaried Commissioned Employee
5)Exit

1
Enter First Name: Dhwanit
Enter Last Name: Kapur
Enter id: 1023
Base Salary: 20000

EMPLOYEE DETAILS:

Name: Dhwanit Kapur
ID: 1023
Salary: 20000

Enter Employee to add:
1)Salaried Employee
2)Hourly Employee
3)Commissioned Employee
4)Salaried Commissioned Employee
5)Exit

2
Enter First Name: Chirag
Enter Last Name: Jhawar
Enter id: 1026
Hours of work: 45

EMPLOYEE DETAILS:

Name: Chirag Jhawar
ID: 1026
Salary: 25000

Enter Employee to add:
1)Salaried Employee
2)Hourly Employee
3)Commissioned Employee
4)Salaried Commissioned Employee
5)Exit

3
Enter First Name: Kshitij 
Enter Last Name: Kapoor
Enter id: 1058
PerCent Sales: 54

EMPLOYEE DETAILS:

Name: Kshitij Kapoor
ID: 1058
Salary: 64800

Enter Employee to add:
1)Salaried Employee
2)Hourly Employee
3)Commissioned Employee
4)Salaried Commissioned Employee
5)Exit

4
Enter First Name: Siddhant Sable
Enter Last Name: Enter id: 1073
Base Salary: 4000
PerCent Sales: 41

EMPLOYEE DETAILS:

Name: Siddhant Sable
ID: 1073
Salary: 45000

Thank you for using

Enter Employee to add:
1)Salaried Employee
2)Hourly Employee
3)Commissioned Employee
4)Salaried Commissioned Employee
5)Exit

5
Thank you for using

*/
