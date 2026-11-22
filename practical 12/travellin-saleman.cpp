#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int dist[10][10];             // dist[i][j] = distance from city i to city j
    int city[10];                 // city[] = the order in which we visit cities (we never move city 0)
    int bestPath[10];             // bestPath[] = the best order found so far
    int best = 1000000000;        // best = smallest total distance found so far (start with a huge value)

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter distance matrix: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];    // read the distance from city i to city j

    for (int i = 0; i < n - 1; i++)
        city[i] = i + 1;          // fill with cities 1, 2, 3 ... (city 0 is our fixed starting point)

    do                            // try one route, then the next, until all routes are tried
    {
        int total = 0;            // total distance of this route
        int current = 0;          // we always start from city 0

        for (int i = 0; i < n - 1; i++)       // go through the cities in this order
        {
            total = total + dist[current][city[i]];   // add the distance to the next city
            current = city[i];                        // move to that city
        }

        total = total + dist[current][0];     // finally return back to city 0

        if (total < best)                     // this route is shorter than the best so far
        {
            best = total;                     // save the new best distance
            for (int i = 0; i < n - 1; i++)
                bestPath[i] = city[i];        // save the route that gave it
        }

    } while (next_permutation(city, city + n - 1));   // moves to the next possible order, stops when all are done

    cout << "Minimum cost = " << best << endl;

    cout << "Best route: 0 ";
    for (int i = 0; i < n - 1; i++)
        cout << "-> " << bestPath[i] << " ";  // print the cities in the best order
    cout << "-> 0" << endl;                   // return to the start

    return 0;
}