#include <iostream>
using namespace std;

int main()
{
    int n;
    int graph[100][100];          // graph[a][b] = weight of edge between a and b (0 = no edge)
    int key[100];                 // key[x] = smallest edge weight found so far to connect x to the tree
    int parent[100];              // parent[x] = which node x is connected to in the tree
    int inTree[100] = {0};        // inTree[x] = 1 means x is already in the tree (starts at 0)

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter weight matrix (0 if no edge): " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];   // read the weight between node i and node j

    for (int i = 0; i < n; i++)
        key[i] = 1000000000;      // initially assume every node is very far (largest value)

    key[0] = 0;                   // start from node 0, so its cost is 0
    parent[0] = -1;               // node 0 is the root, it has no parent

    for (int count = 0; count < n; count++)   // we add one node to the tree in each round
    {
        int u = -1;               // u = the node we will pick in this round

        for (int i = 0; i < n; i++)           // find the cheapest node not yet in the tree
        {
            if (inTree[i] == 0 && (u == -1 || key[i] < key[u]))
                u = i;            // this node is cheaper, so pick it
        }

        inTree[u] = 1;            // add the picked node to the tree

        for (int v = 0; v < n; v++)           // check all neighbours of u
        {
            if (graph[u][v] != 0 && inTree[v] == 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];   // found a cheaper edge to reach v
                parent[v] = u;          // remember that v is connected through u
            }
        }
    }

    int total = 0;                // total weight of the minimum spanning tree

    cout << "Edge \tWeight" << endl;
    for (int i = 1; i < n; i++)   // start from 1 because node 0 is the root
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
        total = total + graph[i][parent[i]];   // add this edge's weight to the total
    }

    cout << "Total weight of MST = " << total << endl;
    return 0;
}