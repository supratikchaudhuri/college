/*
Name: Supratik Chaudhuri
Divison: A
Batch: A2
Roll no.: PA 25
*/

/*                   TITLE: Implementation of Dictionary using Binary Search Tree                   */

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class treenode
{
    char word[10], meaning[50];
    treenode *left, *right;
    friend class tree;
};

class tree
{
    treenode *root;
    friend class treenode;

public:
    tree() //Constructor to initialise Root and create a empty binary search tree
    {
        root = NULL;
    }
    void insert(); //Member functions
    void insert(treenode *, treenode *);
    void level_wise();
    void level_wise(treenode *);
    int search_r(char key[10]);
    int search_r(treenode *, char str[10]);
    void search_nr();
    void mirror_r();
    void mirror_r(treenode *);
    void mirror_nr();
    void copy_r();
    treenode *copy_r(treenode *);
    void delete_node();
    void delete_node(treenode *, char key[10]);
    int compare_bst(treenode *, treenode *);
};

void tree::insert() //Function to create a root node
{
    treenode *curr;
    curr = new treenode;
    cout << "\nEnter a Word: ";
    cin >> curr->word;
    cout << "Enter its meaning: ";
    cin >> curr->meaning;
    if (root == NULL)
    {
        root = curr;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        curr->left = NULL;
        curr->right = NULL;
        insert(root, curr);
    }
}

void tree::insert(treenode *temp, treenode *curr) //Function to decide where to add nodes to root node
{
    int flag = 0;
    while (flag == 0)
    {
        if (strcmp(curr->word, temp->word) == -1)           //less than
        {
            if (temp->left == NULL)
            {
                temp->left = curr;
                flag = 1;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = curr;
                flag = 1;
            }
            temp = temp->right;
        }
    }
}

int front, rear;
treenode *q[50];
class queue //Queue class (needed for further operations)
{
public:
    friend class tree;
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
        front++;
        return q[front];
    }
};

void tree::level_wise()
{
    level_wise(root);
}

void tree::level_wise(treenode *temp) //Breath First Search
{
    queue q;
    q.add(temp);
    while (q.isEmptyq() == false)
    {
        treenode *curr;
        curr = new treenode();
        curr = q.remove();
        cout << curr->word << " ";

        if (curr->left != NULL)
            q.add(curr->left);
        if (curr->right != NULL)
            q.add(curr->right);
    }
}

int tree::search_r(char key[10])    //Function to tell whether the node is present in the tree
{
    int flag = 0;
    flag = search_r(root, key);
    return flag;
}

int tree::search_r(treenode *temp, char str[10])
{
    if (temp != NULL)
    {
        if (strcmp(str, temp->word) == 0)
            return 1;
        if (strcmp(str, temp->word) == -1)
            return search_r(temp->left, str);
        else
            return search_r(temp->right, str);
    }
    return 0;
}

//Function to tell whether the node is present in the tree, if yes then prints its information
void tree::search_nr() 
{
    int flag = 0;
    treenode *temp;
    temp = root;
    char key[10];
    cout << "Enter keyword: ";
    cin >> key;

    while (flag == 0)
    {
        if (temp != NULL)
        {
            if (strcmp(key, temp->word) == 0)
            {
                cout << "\nData Found" << endl;
                cout << "Keyword: " << temp->word << endl;
                cout << "Meaning: " << temp->meaning << endl;
                flag = 1;
                break;
            }
            else if (strcmp(key, temp->word) == -1)
                temp = temp->left;
            else
                temp = temp->right;
        }
        else
        {
            cout << "\nData not found" << endl;
            break;
        }
    }
}

//Recursive Function to create mirror image of the given tree
void tree::mirror_r()
{
    mirror_r(root);
    cout << "\nLevel Wise:\t";
    level_wise();
}

void tree::mirror_r(treenode *root)
{
    treenode *temp;
    if (root == NULL)
        return;
    else
    {
        mirror_r(root->left);
        mirror_r(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

//Non-Recursive Function to create mirror image of the given tree
void tree::mirror_nr()
{
    queue q;
    q.add(root);

    while (!q.isEmptyq())
    {
        treenode *curr = q.remove();

        treenode *temp;
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        if (curr->left != NULL)
            q.add(curr->left);
        if (curr->right != NULL)
            q.add(curr->right);
    }
    cout << "\nLevel Wise:\t";
    level_wise();
}

//Driver funtion
//Function to delete a node
void tree::delete_node()
{
    char key[10];
    cout << "Enter the Word to be deleted : ";
    cin >> key;
    if (search_r(key) == 1)
    {
        delete_node(root, key);
        cout << "\n'" << key << "' is deleted from the dictionary." << endl;
    }
    else if (root == NULL)
    {
        cout << "\nTree is empty." << endl;
        return;
    }
    else
    {
        cout << "\nThis word does not exist in the dictionary." << endl;
    }
}

//Main program
void tree::delete_node(treenode *root, char key[10])
{
    treenode *temp, *curr, *parent, *s;
    curr = new treenode;
    parent = new treenode;
    s = new treenode;
    temp = new treenode;
    temp = root;
    while (temp != NULL) //Locate the word from dictionary
    {
        if (strcmp(key, temp->word) == 0)
        {
            curr = temp;
            break;
        }
        else if (strcmp(key, temp->word) == -1)
        {
            parent = temp;
            temp = temp->left;
        }
        else
        {
            parent = temp;
            temp = temp->right;
        }
    }
    if (curr == root) //Deletion of root
    {
        if (curr->right == NULL)
            root = root->left;
        else if (curr->left == NULL)
            root = root->right;
        else if (curr->right != NULL && curr->left != NULL)
        {
            temp = curr->left;
            root = curr->right;
            s = curr->right;
            while (s->left != NULL)
                s = s->left;
            s->left = temp;
        }
    }
    else
    {
        if (curr != root) //Deletion of internal node/leaf node
        {
            if (curr->right == NULL && curr->left == NULL) //Deletion of a leaf node
            {
                if (curr == parent->left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }

            else if (curr->right != NULL && curr->left == NULL) //Deletion of a node with single child
            {
                if (curr == parent->left)
                    parent->left = curr->right;
                else
                    parent->right = curr->right;
            }
            else if (curr->right == NULL && curr->left != NULL)
            {
                if (curr == parent->left)
                    parent->left = curr->left;
                else
                    parent->right = curr->left;
            }
            else //Deletion of a node with two childs
            {
                s = curr->right;
                temp = curr->left;
                while (s->left != NULL)
                {
                    s = s->left;
                }
                s->left = temp;
                if (curr == parent->left)
                    parent->left = curr->right;
                else
                    parent->right = curr->right;
            }
        }
    }
    curr->right = NULL;
    curr->left = NULL;
    delete curr;
}

//Driver funtion
void tree::copy_r()
{
    treenode *temp;
    temp = copy_r(root);

    cout << "\nOrginal Tree:\t";
    level_wise();
    cout << "\nCopied Tree:\t";
    level_wise(temp);
}
//Main program that copies contents of one tree into another
treenode *tree::copy_r(treenode *root)
{
    treenode *temp;
    temp = NULL;
    if (root != NULL)
    {
        temp = new treenode;
        strcpy(temp->word, root->word);
        strcpy(temp->meaning, root->meaning);
        temp->left = copy_r(root->left);
        temp->right = copy_r(root->right);
    }
    return temp;
}


int main()
{
    int ch;
    tree t;
    do
    {
        cout << "\n\t\t\tDICTIONARY : USING BINARY SEARCH TREE" << endl;
        cout << "\n1. Create a Binary Search Tree\n";
        cout << "2. Insert a word\n";
        cout << "3. Level Wise Display[BFS]\n";
        cout << "4. Search [Recursive]\n";
        cout << "5. Search [Non - recursive] (Also gives information about it)\n";
        cout << "6. Mirror [Recursive]\n";
        cout << "7. Mirror [Non - recursive]\n";
        cout << "8. Copy [Recursive]\n";
        cout << "9. Delete a node\n";
        cout << "Enter your choice : ";

        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int x;
            do
            {
                t.insert();
                cout << "'1' to continue, otherwise '0'\t";
                cin >> x;
            } while (x == 1);
            break;
        }
        case 2:
        {
            t.insert();
            break;
        }
        case 3:
        {
            cout << "\nLevel Wise:\t";
            t.level_wise();
            break;
        }
        case 4:
        {
            int x;
            char key[10];
            cout << "Enter keyword: ";
            cin >> key;
            x = t.search_r(key);
            if (x == 1)
                cout << "\nData Found." << endl;
            else
                cout << "\nData not Found" << endl;
            break;
        }
        case 5:
        {
            t.search_nr();
            break;
        }
        case 6:
        {
            t.mirror_r();
            break;
        }
        case 7:
        {
            t.mirror_nr();
            break;
        }
        case 8:
        {
            t.copy_r();
            break;
        }
        case 9:
        {
            t.delete_node();
            break;
        }
        case 10:
        default:
            cout << "Invalid";
        }
    } while (ch >= 1);
    return 0;
}