#include <iostream>
using namespace std;

void insertionSort(int numbers[], int size)
{
    for (int i = 1; i < size; i++)
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
    int numbers[] = {12, 11, 13, 5, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    insertionSort(numbers, size);

    cout << "Array after Insertion Sort: ";

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}