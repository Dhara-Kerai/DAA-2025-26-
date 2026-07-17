// Insertion Sort Algorithm Implementation
#include <iostream>
using namespace std;

void insertionSort(int numbers[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int currentElement = numbers[i];
        int previousIndex = i - 1;

        // Shift elements that are greater than the current element
        while (previousIndex >= 0 && numbers[previousIndex] > currentElement)
        {
            numbers[previousIndex + 1] = numbers[previousIndex];
            previousIndex--;
        }

        // Place the current element in its correct position
        numbers[previousIndex + 1] = currentElement;
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int numbers[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    insertionSort(numbers, n);

    cout << "Array after Insertion Sort: ";

    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}