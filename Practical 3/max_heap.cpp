#include<iostream>
using namespace std;

int main(){
    int arr[100];
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        int j = 2*i+1; // left child
        int k = 2*i+2; // right child
        int largest = arr[i];
        if(j < n && arr[j] > largest){
            largest = arr[j];
        } 
        if(k < n && arr[k] > largest){
             largest = arr[k];
        }
        if(largest != arr[i]){ //If the largest value is different from the parent
            // swap largest value into position i
            if(largest == arr[j]){
                arr[j] = arr[i];
                arr[i] = largest;
            } else {
                arr[k] = arr[i];
                arr[i] = largest;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}