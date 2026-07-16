#include <iostream>
using namespace std;

int partition(int numbers[], int start, int end)
{
    int pivot = numbers[end];
    int smallerIndex = start - 1;

    for (int current = start; current < end; current++)
    {
        if (numbers[current] < pivot)
        {
            smallerIndex++;

            int swapValue = numbers[smallerIndex];
            numbers[smallerIndex] = numbers[current];
            numbers[current] = swapValue;
        }
    }
    int swapValue = numbers[smallerIndex + 1];
    numbers[smallerIndex + 1] = numbers[end];
    numbers[end] = swapValue;

    return smallerIndex + 1;
}

void quickSort(int numbers[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(numbers, start, end);

        quickSort(numbers, start, pivotIndex - 1);
        quickSort(numbers, pivotIndex + 1, end);
    }
}

int main()
{
    int numbers[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    quickSort(numbers, 0, size - 1);

    cout << "Array after Quick Sort: ";

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}