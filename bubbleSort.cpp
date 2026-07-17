#include <iostream>
using namespace std;

void bubbleSort(int numbers[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-i-1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp= numbers[j];
                numbers[j]=numbers[j + 1];
                numbers[j+1]=temp;
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

//BC O(n²) SC O(1) 
