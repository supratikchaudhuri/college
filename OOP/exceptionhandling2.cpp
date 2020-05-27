#include<iostream>
using namespace std;
class employee
{
	private:
		int id;
		string name;
		int age;
		int income;
		string city;
		string vehicle;
	public:
		
		
		employee(int id1,string n, int a, int in, string c, string v)
		{
			id=id1;
			name=n;
			age=a;
			income=in;
			city=c;
			vehicle=v;
		}
		
		void display()
		{
			cout<<" \nEmployee ID- "<<id;
			cout<<" \nName- "<<name;
			cout<<" \nAge- "<<age;
			cout<<" \nIncome- "<<income;
			cout<<" \nCity- "<<city;
			cout<<" \n Vehicle- "<<vehicle;
		}
};



int main()
{
	int i;
	int w,x;
	string y,z;
	
	try
	{
		cout<<"Enter age: ";
		cin>>w;
		if(w<18 || w>55)
			throw w;
		cout<<"Enter income: ";
		cin>>x;
		if(x<50000 || x>100000)
			throw x;
		cout<<"Enter city: ";
		cin>>y;
		if(y!="Mumbai" && y!="Pune" && y!="Bangalore" && y!="Chennai")
			throw y;
		cout<<"Do you have a 4 wheeler? Y or N? : ";
		cin>>z;
		if(z!="Y")
			throw z;
		
		else
		{
			employee e1(11,"SAM",w,x,y,z);
			e1.display();
		}
	}	
		catch(...)
		{
			cout<<"\nSorry you're not acceptable for this job ";	
		}
		
}
/*OUTPUT

Enter age: 25
Enter income: 60000
Enter city: Pune
Do you have a 4 wheeler? Y or N? : Y
 
Employee ID- 11 
Name- SAM 
Age- 25 
Income- 60000 
City- Pune 		 
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

