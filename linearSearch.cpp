#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int n, target;
    // n = number of elements in the array
    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n]; //storing the elements of the array

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the target : ";
    cin >> target; // take target form the user 

    int index = linearSearch(arr, n, target);

    // if the element is not found in the array then we return -1 
    if (index == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << index;

    return 0;
}