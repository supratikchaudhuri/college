/*
Name: Supratik Chaudhuri
Divison: A
Batch: A2
Roll no.: PA 25

OUTPUT INCLUDED
*/

//                                 TITLE:  Graph and  DFS & BFS Traversal                                   

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

class Gnode
{
    string username;
    int id;
    Gnode *next;

public:
    Gnode()
    {
        id = 0;
        username = "\0";
        next = NULL;
    }
    friend class graph;
};

class graph
{

    Gnode *head[20];
    int n;

public:
    void create();
    void adj_list();
    void DFS_n();
    void DFS_n(int pos, int *);
    void DFS_nr();
    void BFS_nr();
};

void graph::create()
{
    cout << "Enter number of users: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        head[i] = new Gnode;
        cout << "\nEnter Username: ";
        cin >> head[i]->username;
        cout << "Enter User-ID: ";
        cin >> head[i]->id;
    }

    int choice;
    for (int j = 0; j < n; j++)
    {
        Gnode *temp, *curr;
        temp = head[j];

        do
        {
            curr = new Gnode;
            cout << "\nEnter names who are friends with " << head[j]->username << " : ";
            cin >> curr->username;
            curr->next = NULL;

            if (curr->username == head[j]->username)
            {
                cout << "Same username exists." << endl;
                delete curr;
            }
            else
            {
                temp->next = curr;
                temp = temp->next;
            }
            cout << "'1' to continue, Otherwise '0':\t";
            cin >> choice;
        } while (choice == 1);
    }
}

void graph::adj_list()
{
    Gnode *temp;
    cout << "\nUsers and their friend list\n";
    for (int j = 0; j < n; j++)
    {
        temp = head[j];
        temp = temp->next;
        cout << "\n";
        cout << head[j]->username << "\t\t\t\t:\t";
        while (temp != NULL)
        {
            cout << temp->username << "\t\t";
            temp = temp->next;
        }
    }
}

void graph::DFS_n()
{
    int visited[n];
    string name;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    cout << "\nEnter starting name: ";
    cin >> name;

    int pos = 0;
    while (name != head[pos]->username)
        pos++;

    cout << "DFS:\t";
    DFS_n(pos, visited);
}

void graph::DFS_n(int pos, int *visited)
{
    cout << head[pos]->username << "\t\t";
    visited[pos] = 1;

    int loc = 0;
    Gnode *temp;

    for (temp = head[pos]->next; temp != NULL; temp = temp->next)
    {
        while (temp->username != head[loc]->username)
            loc++;

        if (!visited[loc])
            DFS_n(loc, visited);
    }
}

void graph::DFS_nr()
{
    stack<int> s;
    int visited[n];
    string name;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    cout << "\nEnter starting name: ";
    cin >> name;

    int pos = 0;
    while (name != head[pos]->username)
        pos++;
    s.push(pos);

    do
    {
        pos = s.top();
        s.pop();
        cout << head[pos]->username << "\t\t";
        visited[pos] = 1;

        Gnode *temp;
        int loc = 0;

        for (temp = head[pos]->next; temp != NULL; temp = temp->next)
        {
            while (temp->username != head[loc]->username)
                loc++;

            if (!visited[loc])
            {
                s.push(loc);
                visited[loc] = 1;
            }
        }
    } while (!s.empty());
}

void graph::BFS_nr()
{
    queue<int> q;
    int visited[n];
    string name;

    for (int j = 0; j < n; j++)
        visited[j] = 0;

    cout << "\nEnter starting name: ";
    cin >> name;

    int pos = 0;
    while (name != head[pos]->username)
        pos++;

    q.push(pos);
    visited[pos] = 1;

    while (!q.empty())
    {
        pos = q.front();
        q.pop();
        cout << head[pos]->username << "\t\t";
        Gnode *temp;
        int loc = 0;

        for (temp = head[pos]->next; temp != NULL; temp = temp->next)
        {
            while (temp->username != head[loc]->username)
                loc++;

            if (!visited[loc])
            {
                q.push(loc);
                visited[loc] = 1;
            }
        }
    }
}

int main()
{
    graph g;
    int x;
    do
    {
        cout << "\n\n1. Create";
        cout << "\n2. Display Adjacency List";
        cout << "\n3. DFS";
        cout << "\n4. DFS [Non-recursive]";
        cout << "\n5. BFS [Non-recursive]";
        cout << "\nEnter your choice: ";
        cin >> x;
        switch (x)
        {
        case 1:
        {
            g.create();
            break;
        }
        case 2:
        {
            g.adj_list();
            break;
        }
        case 3:
        {
            g.DFS_n();
            break;
        }
        case 4:
        {
            cout << "DFS:\t";
            g.DFS_nr();
            break;
        }
        case 5:
        {
            cout << "BFS:\t";
            g.BFS_nr();
            break;
        }
        default:
        {
            cout << "Invalid Input";
            break;
        }
        }
    } while (x >= 1);
    return 0;
}

/*

Microsoft Windows [Version 6.3.9600]
(c) 2013 Microsoft Corporation. All rights reserved.

F:\Shreyas\Study\Trimester 6\DS-II\CPP>g++ graph.cpp

F:\Shreyas\Study\Trimester 6\DS-II\CPP>a.exe


1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
Enter your choice: 1
Enter number of users: 5

Enter Username: Shreyas
Enter User-ID: 1

Enter Username: Vaidehi
Enter User-ID: 2

Enter Username: Digvijay
Enter User-ID: 3

Enter Username: Prajol
Enter User-ID: 4

Enter Username: Rajat
Enter User-ID: 5

Enter names who are friends with Shreyas : Vaidehi
'1' to continue, Otherwise '0': 1

Enter names who are friends with Shreyas : Digvijay
'1' to continue, Otherwise '0': 1

Enter names who are friends with Shreyas : Prajol
'1' to continue, Otherwise '0': 0

Enter names who are friends with Vaidehi : Rajat
'1' to continue, Otherwise '0': 1

Enter names who are friends with Vaidehi : Digvijay
'1' to continue, Otherwise '0': 1

Enter names who are friends with Vaidehi : Shreyas
'1' to continue, Otherwise '0': 1

Enter names who are friends with Vaidehi : Prajol
'1' to continue, Otherwise '0': 0

Enter names who are friends with Digvijay : Shreyas
'1' to continue, Otherwise '0': 1

Enter names who are friends with Digvijay : Vaidehi
'1' to continue, Otherwise '0': 1

Enter names who are friends with Digvijay : Rajat
'1' to continue, Otherwise '0': 0

Enter names who are friends with Prajol : Rajat
'1' to continue, Otherwise '0': 1

Enter names who are friends with Prajol : Digvijay
'1' to continue, Otherwise '0': 1

Enter names who are friends with Prajol : Shreyas
'1' to continue, Otherwise '0': 0

Enter names who are friends with Rajat :
Vaidehi
'1' to continue, Otherwise '0': 1

Enter names who are friends with Rajat : Shreyas
'1' to continue, Otherwise '0': 1

Enter names who are friends with Rajat : Digvijay
'1' to continue, Otherwise '0': 0


1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
Enter your choice: 2

Users and their friend list

Shreyas                         :       Vaidehi         Digvijay                Prajol
Vaidehi                         :       Rajat           Digvijay                Shreyas         Prajol
Digvijay                        :       Shreyas         Vaidehi         Rajat
Prajol                          :       Rajat           Digvijay                Shreyas
Rajat                           :       Vaidehi         Shreyas         Digvijay

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
Enter your choice: 3

Enter starting name: Vaidehi
DFS:    Vaidehi         Rajat           Shreyas         Digvijay            Prajol     

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
Enter your choice: 4
DFS:    Vaidehi         Prajol          Digvijay            Shreyas         Rajat

1. Create
2. Display Adjacency List
3. DFS
4. DFS [Non-recursive]
5. BFS [Non-recursive]
Enter your choice: 5
BFS:    Vaidehi         Rajat           Digvijay            Shreyas         Prajol
*/