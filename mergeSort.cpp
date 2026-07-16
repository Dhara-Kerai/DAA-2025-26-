#include <iostream>
using namespace std;

void merge(int numbers[], int start, int mid, int end)
{
    int mergedArray[100];

    int left = start;
    int right = mid + 1;
    int index = 0;

    while (left <= mid && right <= end)
    {
        if (numbers[left] <= numbers[right])
        {
            mergedArray[index] = numbers[left];
            left++;
        }
        else
        {
            mergedArray[index] = numbers[right];
            right++;
        }
        index++;
    }

    // Copy remaining elements from the left half
    while (left <= mid)
    {
        mergedArray[index] = numbers[left];
        left++;
        index++;
    }

    // Copy remaining elements from the right half
    while (right <= end)
    {
        mergedArray[index] = numbers[right];
        right++;
        index++;
    }

    // Copy the merged elements back into the original array
    for (int i = start, j = 0; i <= end; i++, j++)
    {
        numbers[i] = mergedArray[j];
    }
}

void mergeSort(int numbers[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;

        mergeSort(numbers, start, middle);
        mergeSort(numbers, middle + 1, end);

        merge(numbers, start, middle, end);
    }
}

int main()
{
    int numbers[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    mergeSort(numbers, 0, size - 1);

    cout << "Array after Merge Sort: ";

    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}