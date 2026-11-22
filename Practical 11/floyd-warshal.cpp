#include <iostream>
using namespace std;

int main()
{
    int n;
    int dist[100][100];           // dist[i][j] = shortest distance from node i to node j

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter distance matrix (use 9999 if no direct edge): " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];    // read the direct distance from i to j

    for (int k = 0; k < n; k++)               // k = the middle node we are allowed to pass through
    {
        for (int i = 0; i < n; i++)           // i = starting node
        {
            for (int j = 0; j < n; j++)       // j = ending node
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])   // going through k is shorter than the current path
                    dist[i][j] = dist[i][k] + dist[k][j];   // update to the shorter distance
            }
        }
    }

    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] >= 9999)           // still 9999 means no path exists
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";   // print the shortest distance
        }
        cout << endl;                         // new line after each row
    }

    return 0;
}