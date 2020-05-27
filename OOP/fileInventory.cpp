#include<iostream>
#include<fstream>
using namespace std;

class item
{
	int id;
	int q;
	float cost;
	char name[30];
	
	public:
		void addItem()
		{
			item i;
			fstream f;
			i.accept();
			f.open("inv1.txt", ios::app| ios::binary);
			f.write((char*)&i,sizeof(i));
			cout<<"\n\nItem added"<<endl;;
			f.close();
			
		}
		void accept()
		{
			cout<<"\nEnter item id : ";
			cin>>id;
			cout<<"\nEnter item name : ";
			cin>>name;
			cout<<"\nEnter quantity : ";
			cin>>q;
			cout<<"\nEnter cost : ";
			cin>>cost;
		}
		void display()
		{
			cout<<"\nItem id \t: "<<id;
			cout<<"\nItem name \t: "<<name;
			cout<<"\nItem quantity \t: "<<q;
			cout<<"\nItem cost \t: "<<cost<<endl;
		}
		void displayList()
		{
			item i;
			fstream fin;
			fin.open("inv1.txt",ios::in| ios::binary);		
			while(fin.read((char*)&i,sizeof(i)))
			{
				i.display();
			}
			fin.close();
		}
		void modify()
		{
			item i;
			fstream f;
			int h,n;
			f.open("inv1.txt",ios::in|ios::out|ios::binary|ios::ate);
			cout<<"Enter id to be searched"<<endl;
			cin>>h;
			f.seekg(0);
			while(f.read((char*)&i,sizeof(item)))
			{
				if(i.id==h)
				{
					cout<<"Enter the quantity of items you want..."<<endl;
					cin>>n;
					i.q=i.q-n;
					f.seekp(-sizeof(item),ios::cur);
					f.write((char*)&i,sizeof(item));
				}
			}
			f.close();
		}
};
int main()
{
	item i;
	int n,k=0;
	char ch;
	while(k==0)
	{
		cout<<"Menu"<<endl;
		cout<<"1. Add Item"<<endl;
		cout<<"2. Display Items"<<endl;
		cout<<"3. Modify Items"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter choice"<<endl;
		cin>>n;
		switch(n)
		{
			case 1: cout<<"Enter item details"<<endl;
			i.addItem();
				break;
			case 2: cout<<"Current Inventory"<<endl;
			i.displayList();
			break;
			case 3: cout<<endl;
			i.modify();
			break;
			case 4: cout<<"Are u sure u want to exit?? Y/N"<<endl;
			cin>>ch;
			if(ch=='Y')
				k=1;
			break;
			default: cout<<"Invalid Input"<<endl;
		}
	}
return 0;
}

/*OUTPUT - 
ibm@IBM:~$ g++ inv.cpp
ibm@IBM:~$ ./a.out
Menu
1. Add Item
2. Display Items
3. Modify Items
4. Exit
Enter choice
1
Enter item details

Enter item id : 11

Enter item name : pen

Enter quantity : 20

Enter cost : 5


Item added
Menu
1. Add Item
2. Display Items
3. Modify Items
4. Exit
Enter choice
1
Enter item details

Enter item id : 22

Enter item name : pencil

Enter quantity : 20

Enter cost : 1


Item added
Menu
1. Add Item
2. Display Items
3. Modify Items
4. Exit
Enter choice
2
Current Inventory

Item id 	: 11
Item name 	: pen
Item quantity 	: 20
Item cost 	: 5

Item id 	: 22
Item name 	: pencil
Item quantity 	: 20
Item cost 	: 1
Menu
1. Add Item
2. Display Items
3. Modify Items
4. Exit
Enter choice
3

Enter id to be searched
22
Enter the quantity of items you want...
7
Menu
1. Add Item
2. Display Items
3. Modify Items
4. Exit
Enter choice
2
Current Inventory

Item id 	: 11
Item name 	: pen
Item quantity 	: 20
Item cost 	: 5

Item id 	: 22
Item name 	: pencil
Item quantity 	: 13
Item cost 	: 1
Menu
1. Add Item
2. Display Items
3. Modify Items
4. Exit
Enter choice
4
Are u sure u want to exit?? Y/N
Y
*/




