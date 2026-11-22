#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, amount;
    int coins[100];
    int dp[10001];   //dp[i] stores the minimum number of coins required to make amount i.
    
    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    dp[0] = 0;   // 0 amount needs 0 coins

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = 1000000000;   // assume not possible at first

        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    if (dp[amount] >= 1000000000)
        cout << "Not possible" << endl;
    else
        cout << "Minimum coins needed = " << dp[amount] << endl;

    return 0;
}