#include<iostream>
#include<string.h>
using namespace std;



class employee //class employee declared
{
	
		
	public:
		char name[10],vehicle;
		string city;
		int id,age;
		double income;
		
		employee(char n[],int a, double i, string c, char v) //parametrized constructor
		{
			strcpy(name,n);
			age=a;
			income=i;
			city=c;
			vehicle=v;
		}

		void display()
		{
			cout<<name<<" is an Employee.\n";
		}
};

int main()
{
	char name[10];
	char vehicle;
	string city;
	int id,age;
	double income;
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter ID: ";
	cin>>id;
	try //try block
			{
				cout<<"Enter Age: ";
				cin>>age;
				if(age<18 || age>55)
					throw age; //variable thrown to respective catch
				cout<<"Enter income: ";
				cin>>income;
				if(income<50000 || income>100000) 
					throw income; //variable thrown to respective catch
				cout<<"Select City (Pune,Mumbai,Banglore,Chennai): ";
				cin>>city;
				if(city!="Pune" && city!="Mumbai" && city!="Banglore" && city!="Chennai")
					throw city; //variable thrown to respective catch
				cout<<"Vehicle 4 wheeler?(Y/N): ";
				cin>>vehicle;
				if(vehicle=='N' || vehicle== 'n')
					throw vehicle; //variable thrown to respective catch
				else
				{
					employee e(name,age,income,city,vehicle); //object is created once all the conditions are satisfied
					e.display();
				}
			} 
			catch(int x)// catch block for int
			{	
				cout<<"As age is "<<x<<", "<<name<<" is not an employee.\n";
				
			}
			catch(double y) //catch block for double
			{
				cout<<"As income is not between 50,000 and 1,00,000, "<<name<<" is not an employee.\n";
			}
			catch(string v) //catch block for string
			{
				cout<<"As city condition is not satisfied, "<<name<<" is not an employee.\n";
			}
			catch(char z) //catch block for char
			{
				cout<<"As no 4 wheeler, "<<name<<" is not an employee.\n";
			}
	
	
	
}

/*
OUTPUT:

Enter name: AD
Enter ID: 123
Enter Age: 34
Enter income: 52000
Select City (Pune,Mumbai,Banglore,Chennai): Mumbai
Vehicle 4 wheeler?(Y/N): Y
AD is an Employee.

Enter name: DK
Enter ID: 453
Enter Age: 17
As age is 17, DK is not an employee.

Enter name: Sid
Enter ID: 215
Enter Age: 23
Enter income: 45000
As income is not between 50,000 and 1,00,000, Sid is not an employee.

Enter name: Chirag
Enter ID: 678
Enter Age: 40
Enter income: 90000
Select City (Pune,Mumbai,Banglore,Chennai): Gurgaon
As city condition is not satisfied, Chirag is not an employee.

Enter name: Kshitij
Enter ID: 980
Enter Age: 29
Enter income: 52000
Select City (Pune,Mumbai,Banglore,Chennai): Mumbai
Vehicle 4 wheeler?(Y/N): N
As no 4 wheeler, Kshitij is not an employee.

*/
