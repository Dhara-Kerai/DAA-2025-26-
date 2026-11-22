#include <iostream>
using namespace std;

int parent[100];                  // parent[x] = the "leader" of the group that x belongs to

int findLeader(int x)
{
    while (parent[x] != x)        // keep going up until we reach the leader (leader's parent is itself)
        x = parent[x];
    return x;                     // this is the leader of the group
}

int main()
{
    int n, e;
    int u[100], v[100], w[100];   // edge i connects u[i] and v[i] with weight w[i]

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (node1 node2 weight): " << endl;
    for (int i = 0; i < e; i++)
        cin >> u[i] >> v[i] >> w[i];   // read one edge

    for (int i = 0; i < n; i++)
        parent[i] = i;            // in the beginning every node is its own group (its own leader)

    for (int i = 0; i < e - 1; i++)           // sort the edges by weight (smallest first)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (w[j] > w[j + 1])              // if this edge is heavier than the next one
            {
                swap(w[j], w[j + 1]);         // swap the weights
                swap(u[j], u[j + 1]);         // swap the first nodes
                swap(v[j], v[j + 1]);         // swap the second nodes
            }
        }
    }

    int total = 0;                // total weight of the minimum spanning tree
    int count = 0;                // number of edges we have picked so far

    cout << "Edge \tWeight" << endl;
    for (int i = 0; i < e; i++)               // go through edges from smallest to largest
    {
        int a = findLeader(u[i]);             // leader of the group of the first node
        int b = findLeader(v[i]);             // leader of the group of the second node

        if (a != b)                           // different groups means NO cycle will be formed
        {
            cout << u[i] << " - " << v[i] << " \t" << w[i] << endl;   // pick this edge
            total = total + w[i];             // add its weight to the total
            parent[a] = b;                    // join the two groups into one
            count++;                          // one more edge picked
        }

        if (count == n - 1)                   // a tree with n nodes needs only n-1 edges
            break;                            // so we can stop
    }

    cout << "Total weight of MST = " << total << endl;
    return 0;
}