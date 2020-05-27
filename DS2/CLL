#include <iostream>
#include <math.h>
using namespace std;

class node
{
public:
    int coef, exp;
    class node *next;
    friend class poly;
};

class poly
{
public:
    class node *head, *temp, *curr;

    poly()                                      //Constructor to initialise a node with the following values
    {
        head = new node;
        head->coef = 0;
        head->exp = -1;
        head->next = head;
    }
    void create();                              //To create polynomial
    void display();                             //To display polynomial
    void remove_dup();                          //To remove terms with same exponent
    void add(poly p1, poly p2);                 //To add two polynomials
    void eval();                                //To find the value of the polynomial at some certain value of x
    void mul(poly p1, poly p2);                 //PRACTICE ASSIGNMENT: To find product of two polynomials
};

//Function to create polynomial
void poly ::create()
{
    cout << "\n*************************************************************************\n";
    cout << "\t\t\tCREATION OF POLYNOMIAL\n\n"
         << endl;
    temp = head;
    int ch;
    do
    {
        curr = new node;
        temp->next = curr;
        cout << "Enter coefficient: ";
        cin >> curr->coef;
        cout << "Enter Exponent: ";
        cin >> curr->exp;
        curr->next = head;
        temp = temp->next;
        cout << "Press 1 to ADD, 0 to STOP: ";
        cin >> ch;
    } while (ch == 1);
}

//Function to display polynomial
void poly ::display()
{
    temp = head->next;
    while (temp != head)
    {
        if (temp->coef != 0)
        {
            cout << temp->coef << "x^" << temp->exp;
            temp = temp->next;
            if (temp == head)
                break;
            cout << " + ";
        }
        else
        {
            temp = temp->next;
        }
    }
}

//Function to remove terms with same exponent
void poly::remove_dup()
{
    class node *ptr1, *ptr2, *dup;
    ptr1 = head->next;
    while (ptr1 != head && ptr1->next != head)
    {
        ptr2 = ptr1;
        while (ptr2->next != head)                      // Compare the elements with remaining of the elements
        {
            if (ptr1->exp == ptr2->next->exp)           //If elements with same exponent are found
            {
                ptr1->coef = ptr1->coef + ptr2->next->coef;             //Add those elements
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete dup;
            }
            else
                ptr2 = ptr2->next;                      
        }
        ptr1 = ptr1->next;
    }
}
//Fucntion to add two polynomials
void poly ::add(poly p1, poly p2)
{
    class node *expr1, *expr2, *result, *temp;
    expr1 = p1.head->next;
    expr2 = p2.head->next;
    temp = head;
    while (expr1->exp != -1 || expr2->exp != -1)
    {
        result = new node;
        if (expr1->exp == expr2->exp)                       //If exponents are same
        {
            result->exp = expr1->exp;
            result->coef = expr1->coef + expr2->coef;
            result->next = head;
            expr1 = expr1->next;
            expr2 = expr2->next;
            temp->next = result;
            temp = result;
        }
        else if (expr1->exp > expr2->exp)                   //If exponent of 1st expression is greater then 2nd expression
        {
            result->exp = expr1->exp;                       //So we just copy the data of 1st expression and traverse ahead
            result->coef = expr1->coef;
            result->next = head;
            expr1 = expr1->next;
            temp->next = result;
            temp = result;
        }
        else if (expr1->exp < expr2->exp)                    //If exponent of 2st expression is greater then 1nd expression
        {
            result->exp = expr2->exp;                       //So we just copy the data of 2st expression and traverse ahead
            result->coef = expr2->coef;
            result->next = head;
            expr2 = expr2->next;
            temp->next = result;
            temp = result;
        }
    }
    remove_dup();
    display();
}

//Function to find the value of the polynomial at some certain value of x
void poly::eval()
{
    int sum = 0, x;
    cout << "\nEnter value of x: ";
    cin >> x;
    temp = head->next;
    while (temp != head)
    {
        sum = sum + (temp->coef * pow(x, temp->exp));
        temp = temp->next;
    }
    cout << "Value of ";
    display();
    cout << " at x = " << x << " is " << sum;
}

//PRACTICE ASSIGNMENT: Function to find product of two polynomials
void poly ::mul(poly p1, poly p2)
{
    node *expr1, *expr2, *temp, *result;
    expr1 = p1.head->next;
    expr2 = p2.head->next;
    temp = head;
    while (expr2 != p2.head)
    {
        while (expr1 != p1.head)
        {
            result = new node;
            result->exp = expr1->exp + expr2->exp;
            result->coef = expr1->coef * expr2->coef;
            result->next = head;
            expr1 = expr1->next;
            temp->next = result;
            temp = result;
            temp->next = head;
        }
        expr2 = expr2->next;
        expr1 = p1.head->next;
    }
    remove_dup();
    display();
}

int main()
{
    poly p1, p2, p3, p4;
    int n;
    do
    {
        cout << "\n\n*************************************************************************\n";
        cout << "\t\t\t\tMENU" << endl;
        cout << "\n1. Create 1st Polynomial.\n2. Create 2nd Polynomial.\n3. Display Polynomials.\n4. Addition of Polynomials.\n5. Evaluate.\n6. Multiplication.\n7. Exit.\nEnter your choice:  ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            p1.create();
            break;
        }
        case 2:
        {
            p2.create();
            break;
        }
        case 3:
        {
            cout << "\n\n*************************************************************************\n";
            cout << "\t\t\tPOLYNOMIALS\n\n"
                 << endl;
            cout << "First Polynomial:\t";
            p1.display();
            cout << "\nSecond Polynomial:\t";
            p2.display();
            break;
        }
        case 4:
        {
            cout << "\n\n*************************************************************************\n";
            cout << "\t\t\tADDITION OF POLYNOMIAL\n\n";
            p1.display();
            cout << "\n+" << endl;
            p2.display();
            cout << "\n------------------------------------------" << endl;
            p3.add(p1, p2);
            break;
        }
        case 5:
        {
            cout << "\n\n*************************************************************************\n";
            cout << "\t\t\tEVALUATION OF POLYNOMIAL" << endl;
            p1.eval();
            p2.eval();
            break;
        }
        case 6:
        {
            cout << "\n\n*************************************************************************\n";
            cout << "\t\t\tMULTIPLICATION OF POLYNOMIAL\n\n";
            cout << "(";
            p1.display();
            cout << ")";
            cout << "   x   ";
            cout << "(";
            p2.display();
            cout << ")";
            cout << "    =    ";
            p4.mul(p1, p2);
            break;
        }
        }
    } while (1 <= n < 7);
    return 0;
}
