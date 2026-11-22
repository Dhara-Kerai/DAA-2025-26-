#include<iostream>
using namespace std;

// Places the pivot in its correct position and returns its index.
int partition(int A[], int low , int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do{
        while(A[i] <= pivot && i <= high){ //i<=high is added to avoid going out of bounds
            i++;
        }
        while(A[j] > pivot && j >= low){//j>=low stop j before it goes below the first valid index.
            j--;
        }
        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
} while(i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
// Calls partition() and recursively sorts the left and right subarrays.
void quickSort(int A[], int low, int high){
    if(low < high){
        int partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter the elements: "; 
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    quickSort(A, 0, n - 1);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    cout << endl;

    return 0;

}