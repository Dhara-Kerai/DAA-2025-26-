#include <iostream>
using namespace std;

void selectionSort(int numbers[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
  
        int smallestIndex = i;


        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < numbers[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        // Swap the current element with the smallest element
        int swapValue = numbers[i];
        numbers[i] = numbers[smallestIndex];
        numbers[smallestIndex] = swapValue;
    }
}

int main()
{
    int numbers[] = {64, 25, 12, 22, 11};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    selectionSort(numbers, size);

    cout << "Array after Selection Sort: ";

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}