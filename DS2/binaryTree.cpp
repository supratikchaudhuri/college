/*
Name: Supratik Chaudhuri
Divison: A
Batch: A2
Roll no.: PA 25
*/

/*                         TITLE : Binary tree and its Traversal Methods                            */

#include <iostream>
using namespace std;

class treenode
{
    int data;
    treenode *l, *r;
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree() //Constructor to initialise Root and create a empty binary tree
    {
        root = NULL;
    }
    void create_r(); //Member functions
    void create_r(treenode *);
    void inorder_r();
    void inorder_r(treenode *);
    void preorder_r();
    void preorder_r(treenode *);
    void postorder_r();
    void postorder_r(treenode *);
    void create_nr();
    void inorder_nr();
    void preorder_nr();
    void postorder_nr();
    void bfs();
    void depth_nr();
    void depth_r();
    int depth_r(treenode *);
};

void tree ::create_r() //Driver function
{
    root = new treenode;
    cout << "Enter data for root: ";
    cin >> root->data;
    root->l = NULL;
    root->r = NULL;
    create_r(root);
}

void tree ::create_r(treenode *temp) //Main function
{
    treenode *curr;
    char ch;

    cout << "\nDo you want to enter data on left of " << temp->data << " ?\nPress 'y', Otherwise 'n'\t";
    cin >> ch;
    if (ch == 'y')
    {
        curr = new treenode;
        cout << "\nEnter data of left child : ";
        cin >> curr->data;
        temp->l = curr;
        create_r(curr);
    }

    cout << "\nDo you want to enter data on right of " << temp->data << " ?\nPress 'y', Otherwise 'n'\t";
    cin >> ch;
    if (ch == 'y')
    {
        curr = new treenode;
        cout << "\nEnter data of right child : ";
        cin >> curr->data;
        temp->r = curr;
        create_r(curr);
    }
}

//Traversal methods with using recursion:

void tree ::inorder_r() //Driver function for Inorder Traversal
{
    inorder_r(root);
}

void tree ::inorder_r(treenode *temp) //Main function for Inorder Traversal
{
    if (temp != NULL)
    {
        inorder_r(temp->l);
        cout << temp->data << "  ";
        inorder_r(temp->r);
    }
}

void tree ::preorder_r() //Driver function for Preorder Traversal
{
    preorder_r(root);
}

void tree ::preorder_r(treenode *temp) //Main function for Preorder Traversal
{
    if (temp != NULL)
    {
        cout << temp->data << "  ";
        preorder_r(temp->l);
        preorder_r(temp->r);
    }
}

void tree ::postorder_r() //Driver function for Postorder Traversal
{
    postorder_r(root);
}

void tree ::postorder_r(treenode *temp) //Driver function for Postorder Traversal
{
    if (temp != NULL)
    {
        postorder_r(temp->l);
        postorder_r(temp->r);
        cout << temp->data << "  ";
    }
}

//Traversal methods without using recursion:

class stack //Stack class (needed for further operations)
{
    friend class tree;
    int top;
    treenode *st[30];

public:
    stack()
    {
        top = -1;
    }
    void push(treenode *temp)
    {
        top++;
        st[top] = temp;
    }
    treenode *pop()
    {
        treenode *temp;
        temp = st[top];
        top--;
        return temp;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    treenode *stacktop()
    {
        return st[top];
    }
};

void tree ::create_nr() //Create function
{
    char ch, ch2;
    treenode *temp, *curr;
    int flag;
    if (root == NULL)
    {
        root = new treenode;
        cout << "Enter data for root: ";
        cin >> root->data;
        root->r = NULL;
        root->l = NULL;
    }
    do
    {
        temp = root;
        curr = new treenode;
        flag = 0;
        cout << "Enter data for node: ";
        cin >> curr->data;
        curr->l = NULL;
        curr->r = NULL;
        while (flag == 0)
        {
            cout << "Do you want to enter node to left [l] or right [r] of " << temp->data << " ?\t";
            cin >> ch2;
            if (ch2 == 'l')
            {
                if (temp->l == NULL)
                {
                    temp->l = curr;
                    flag = 1;
                }
                temp = temp->l;
            }
            else if (ch2 == 'r')
            {
                if (temp->r == NULL)
                {
                    temp->r = curr;
                    flag = 1;
                }
                temp = temp->r;
            }
        }

        cout << "'y' for continue, 'n' to stop: ";
        cin >> ch;
    } while (ch == 'y');
}

void tree ::inorder_nr() //Non-recursive Function for Inorder Traversal
{
    stack s;
    treenode *temp;
    temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->l;
        }
        if (s.isEmpty())
            break;
        temp = s.pop();
        cout << temp->data << " ";
        temp = temp->r;
    }
    cout << "\n";
}

void tree ::preorder_nr() //Non-recursive Function for Preorder Traversal
{
    stack s;
    treenode *temp;
    temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->l;
        }
        if (s.isEmpty())
            break;
        temp = s.pop();
        temp = temp->r;
    }
    cout << "\n";
}

void tree ::postorder_nr() //Non-recursive Function for Postorder Traversal
{
    stack s;
    treenode *temp;
    temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->l;
        }
        if (s.stacktop()->r == NULL)
        {
            temp = s.pop();
            cout << temp->data << " ";
        }
        while (s.stacktop()->r == temp && !s.isEmpty())
        {
            temp = s.pop();
            cout << temp->data << " ";
        }
        if (s.isEmpty())
            break;
        temp = s.stacktop()->r;
    }
    cout << "\n";
}

class queue //Queue class (needed for further operations)
{
    int front, rear;
    treenode *q[30];

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    int isEmptyq()
    {
        if (front == rear)
            return 1;
        else
            return 0;
    }

    void add(treenode *temp)
    {
        rear++;
        q[rear] = temp;
    }

    treenode *remove()
    {
        treenode *temp;
        temp = q[front];
        front++;
        return temp;
    }
};

void tree::bfs() //Breath First Search
{
    queue q;
    treenode *temp;
    temp = root;
    q.add(temp);
    while (!q.isEmptyq())
    {
        temp = q.remove();
        cout << temp->data << " ";

        if (temp->l != NULL)
            q.add(temp->l);
        if (temp->r != NULL)
            q.add(temp->r);
    }
}

//Non-recursive Function to calculate Depth of the tree

void tree::depth_nr()
{
    stack s1;
    treenode *temp;
    int depth = 0;
    temp = root;
    while (1)
    {
        while (temp != NULL)
        {
            s1.push(temp);
            temp = temp->l;
            if (depth < s1.top)
                depth = s1.top;
        }

        if (s1.stacktop()->r == NULL)
            temp = s1.pop();

        while (!s1.isEmpty() && s1.stacktop()->r == temp)
            temp = s1.pop();

        if (s1.isEmpty() == 1)
            break;

        temp = s1.stacktop()->r;
    }
    cout << "\nDepth:\t" << depth + 1 << "\n";
}

//Recursive Function to calculate Depth of the tree

void tree::depth_r() //Driver Function
{
    int d;
    d = depth_r(root);
    cout << "\nDepth:\t" << d << "\n";
}

int tree::depth_r(treenode *temp) //Main Function
{
    int tleft = 0, tright = 0;
    if (temp == NULL)
        return 0;
    else
    {
        tleft = depth_r(temp->l);
        tright = depth_r(temp->r);

        if (tleft > tright)
            return ++tleft;
        else
            return ++tright;
    }
}

int main()
{
    int n;
    tree t;
    do
    {
        cout << "\nRECURSIVE\t\t\tNON-RECURSIVE\n";
        cout << "---------------------------------------------\n";
        cout << "1. Create\t\t\t6. Create\n";
        cout << "2. INORDER\t\t\t7. INORDER\n";
        cout << "3. PREORDER\t\t\t8. PREORDER\n";
        cout << "4. POSTORDER\t\t\t9. POSTORDER\n";
        cout << "5. Depth\t\t\t10. BFS\n";
        cout << "\t\t\t\t11. Depth\n";
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            t.create_r();
            break;
        }
        case 2:
        {
            cout << "\nInorder [Recursive]:\t";
            t.inorder_r();
            break;
        }
        case 3:
        {
            cout << "\nPreorder [Recursive]:\t";
            t.preorder_r();
            break;
        }
        case 4:
        {
            cout << "\nPostorder [Recursive]:\t";
            t.postorder_r();
            break;
        }
        case 5:
        {
            t.depth_nr();
            break;
        }
        case 6:
        {
            t.create_nr();
            break;
        }
        case 7:
        {
            cout << "\nInorder [Non-Recursive]:\t";
            t.inorder_nr();
            break;
        }
        case 8:
        {
            cout << "\nPreorder [Non-Recursive]:\t";
            t.preorder_nr();
            break;
        }
        case 9:
        {
            cout << "\nPostnorder [Non-Recursive]:\t";
            t.postorder_nr();
            break;
        }
        case 10:
        {
            cout << "\nBFS:\t";
            t.bfs();
            break;
        }
        case 11:
        {
            t.depth_r();
            break;
        }
        default:
            break;
        }
    } while (1 <= n < 12);
    return 0;
}