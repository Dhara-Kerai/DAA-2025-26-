//binary Search 
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Target found at index mid
        else if (arr[mid] < target)
            left = mid + 1; // Search in the right half
        else
            right = mid - 1; // Search in the left half
    }

    return -1; // Target not found
}
int main(){
    int n, target;
    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n]; //storing the elements of the array

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the target : ";
    cin >> target; // take target form the user 

    int index = binarySearch(arr, n, target);

    // if the element is not found in the array then we return -1 
    if (index == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << index;

    return 0;
}