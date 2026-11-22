#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, capacity;
    int weight[100], value[100];
    int dp[1000] = {0};   //dp[w]=best value for capacity w(starts at 0)BASE CASE

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    for (int i = 0; i < n; i++)
    {
        for (int w = capacity; w >= weight[i]; w--) //We loop backward so that each item is used only once
                                                    //If you go forward, the same item can get counted many times.
        {
            dp[w] = max(dp[w], value[i] + dp[w - weight[i]]);
        }
    }

    cout << "Maximum value = " << dp[capacity] << endl;
    return 0;
}