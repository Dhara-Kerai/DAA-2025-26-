#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n/2 - 1; i >= 0; i--){
        //n/2-1 will visit only the parents node 
        //we do not need to check the leaf nodes since they don't have further childs
        int current = i;
        while(true){
            int j = 2*current + 1;// left child
            int k = 2*current + 2;// right child
            int largest = current;

            if(j < n && arr[j] > arr[largest]){
                largest = j;
            }
            if(k < n && arr[k] > arr[largest]){
                largest = k;
            }
            if(largest == current){
                break;
            }
            int temp = arr[current];
            arr[current] = arr[largest];
            arr[largest] = temp;

            current = largest;
        }
    }

    for(int i = n - 1; i > 0; i--){

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int current = 0;

        while(true){
            int j = 2*current + 1;   // left child
            int k = 2*current + 2;   // right child
            int largest = current;

            if(j < i && arr[j] > arr[largest]){
                largest = j;
            }
            if(k < i && arr[k] > arr[largest]){
                largest = k;
            }
            if(largest == current){
                break;
            }
            int temp2 = arr[current];
            arr[current] = arr[largest];
            arr[largest] = temp2;

            current = largest;
        }
    }
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}