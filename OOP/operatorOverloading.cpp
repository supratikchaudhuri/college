
#include<iostream>
using namespace std;
class complex //Base Class
{
	int real;
	int imaginary;
public:	complex()
	{
		real=0;
		imaginary=0;
	}

friend	istream& operator >> (istream &in, complex &x) //friend function and extraction operator overloading
	{
		cout<<"Enter real part:\n";
		in>>x.real;
		cout<<"Enter imaginary part;\n";
		in>>x.imaginary;
	}

friend	ostream& operator << (ostream &out, complex &x) // insertion operator overloading
	{
		out<<x.real<<"+"<<x.imaginary<<"i\n";
	}
friend	complex operator +(complex x1, complex x2);
friend	complex operator *(complex x1, complex x2);
};

complex operator +(complex x1, complex x2) // + operator overloading
{
	complex x3;
	x3.real=x1.real+x2.real;
	x3.imaginary=x1.imaginary+x2.imaginary;
	return x3;
}

complex operator *(complex x1, complex x2) // * operator overloading
{
	complex x3;
	x3.real=x1.real*x2.real-x1.imaginary*x2.imaginary;
	x3.imaginary=x1.imaginary*x2.real+x1.real*x2.imaginary;
	return x3;
}
int main()
{
	complex c1,c2,c3; //creating objects
	cin>>c1; // calling overloaded operator
	cout<<c1;
	cin>>c2;
	cout<<c2;
	c3=c1+c2; // calling overloaded operator
	cout<<"Addition is: ";
	cout<<c3;
	c3=c1*c2; // calling overloaded operator
	cout<<"Multiplication is: ";
	cout<<c3;
	return 0;
}

/*
OUTPUT:
Enter real part:
23
Enter imaginary part;
2
23+2i
Enter real part:
12
Enter imaginary part;
34
12+34i
Addition is: 35+36i
Multiplication is: 208+806i

*/

