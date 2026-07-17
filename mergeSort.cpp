#include<iostream>
using namespace std;
void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(int A[], int low, int mid, int high){
    int i, j , k , B[100];
    i = low;
    j = mid + 1;
    k = low;

    // merge the two subarrays into B[]
    while(i <= mid && j <= high){
        if(A[i] <= A[j]){
            B[k] = A[i];
            i++;
            k++;
        } else {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    // copy the remaining elements of the left subarray, if there are any
    while(i <= mid){
        B[k] = A[i];
        i++;
        k++;
    }
    // copy the remaining elements of the right subarray, if there are any
    while(j <= high){
        B[k] = A[j];
        j++;
        k++;
    }
    // copy the merged elements back into the original array
    for(i = low; i <= high; i++){
        A[i] = B[i];
    }

    void mergeSort(int A[], int low, int high){
        int mid;
        if(low < high){
            int mid = (low + high) / 2;
            mergeSort(A, low, mid);
            mergeSort(A, mid + 1, high);
            merge(A, low, mid, high);
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
        mergeSort(A, 0, n - 1);
        cout << "Sorted array: ";
        printArray(A, n);

        return 0;
    }