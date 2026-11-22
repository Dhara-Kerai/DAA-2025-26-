#include <iostream>
using namespace std;

int n;                 // total number of nodes
int graph[100][100];   // graph[a][b] = 1 means a and b are connected (starts at 0 = no edge)
int visited[100];      // visited[x] = 1 means node x is already seen (starts at 0)

void dfs(int node)
{
    cout << node << " ";           // print the node we are standing on
    visited[node] = 1;             // mark it as seen so we never come back to it

    for (int i = 0; i < n; i++)    // look at every possible neighbour
    {
        if (graph[node][i] == 1 && visited[i] == 0)   // connected AND not seen yet
            dfs(i);                // go deep into that neighbour first (recursion)
    }
}

void bfs(int start)
{
    int queue[100];                // a simple array that works like a queue
    int front = 0, rear = 0;       // front = who to take next, rear = where to add next

    queue[rear] = start;           // put the starting node in the queue
    rear++;                        // move rear forward
    visited[start] = 1;            // mark start as seen

    while (front < rear)           // keep going until the queue is empty
    {
        int node = queue[front];   // take the node at the front
        front++;                   // move front forward (this removes it)
        cout << node << " ";       // print it

        for (int i = 0; i < n; i++)    // look at every possible neighbour
        {
            if (graph[node][i] == 1 && visited[i] == 0)   // connected AND not seen yet
            {
                queue[rear] = i;   // add the neighbour at the back of the queue
                rear++;            // move rear forward
                visited[i] = 1;    // mark it seen right away so it is not added twice
            }
        }
    }
}

int main()
{
    int edges, a, b, start;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (like 0 1): " << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        graph[a][b] = 1;           // a is connected to b
        graph[b][a] = 1;           // b is connected to a (undirected graph, works both ways)
    }

    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS: ";
    dfs(start);                    // run DFS from the start node
    cout << endl;

    for (int i = 0; i < n; i++)
        visited[i] = 0;            // reset visited so BFS can start fresh

    cout << "BFS: ";
    bfs(start);                    // run BFS from the start node
    cout << endl;

    return 0;
}