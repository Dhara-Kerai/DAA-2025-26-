#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int p[101];
    int dp[101][101] = {0};   // dp[i][j] = min cost to multiply matrices i to j

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimensions (p0 p1 p2 ... pn): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 1000000000; //initially assume the largest value 

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << "Minimum multiplications = " << dp[1][n] << endl;
    return 0;
}