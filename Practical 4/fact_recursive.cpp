// fact using recursive method
#include <iostream>
using namespace std;
int factorial(int n)
{
    if(n == 0||n==1)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int fact = factorial(n);
    cout << "Factorial = " << fact << endl;
    return 0;
}
// TC = O(n) bcz each value of n is multiplied with the factorial of n-1 and go so on until it reaches 1.