#include <iostream>
using namespace std;

void bubbleSort(int numbers[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
    {
        for (int current = 0; current < size - pass - 1; current++)
        {
            if (numbers[current] > numbers[current + 1])
            {
                int swapValue = numbers[current];
                numbers[current] = numbers[current + 1];
                numbers[current + 1] = swapValue;
            }
        }
    }
}

int main()
{
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    bubbleSort(numbers, size);

    cout << "Array after Bubble Sort: ";

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}