// Supratik Chaudhuri
// PA25


#include <iostream>
using namespace std;

class prim {
    int nodes, min;
    int cost[50][50], visited[50];

    public:
        prim();
        void input();
        void output();
        void minSpanningTree();
};

prim::prim() {

    cout<<"\nEnter number of cities : ";
    cin>>nodes;
}

void prim::input() {

    cout<<"\nEnter cost of connection between the cities. Enter 0 if no connection exists.\n";

    int charge;

    for(int i= 0; i<nodes; i++) {

        visited[i] = 0;

       for(int j = i+1; j<nodes; j++) {

              

           cout<<"Cost of connection between cities "<<i<<" and "<<j<<" : ";
           cin>>charge;

           cost[i][j] = cost[j][i] = charge;
       }
    }
}

void prim::output() {

    cout<<"\nCost adjacency matrix :";

    for(int i = 0; i<nodes; i++) {

        cout<<"\n";
        for(int j = 0; j<nodes; j++) {
            cout<<cost[i][j]<<"\t";
        }
    }
}

void prim::minSpanningTree() {

    int start;

    cout<<"\n\nEnter starting city : ";
    cin>>start;
    visited[start] = 1;

    cout<<"\n\nMinimum Spanning Tree:";
    int u, v, total = 0;

    for(int counter = 0; counter < nodes-1; counter++) {

        min = 999;

        for(int i = 0; i<nodes; i++) {

            if(visited[i] == 1) {

                for(int j = 0; j<nodes; j++) {

                    if(visited[j]==0) {

                        if(cost[i][j] < min &&cost[i][j]!=0) {

                            min = cost[i][j];
                            u =  i;
                            v = j;
                        }
                    }
                }
            }
        }

        visited[v] = 1;
        total += min;
        // cost[u][v] = 0;
        cout<<"\nConnection : "<<u<<" and "<<v<<";\tcost : "<<min;
    }

    cout<<"\n\nMinimum cost : "<<total;
}

int main() {

    prim ob;
    ob.input();
    ob.output();
    ob.minSpanningTree();

    return 0;
}