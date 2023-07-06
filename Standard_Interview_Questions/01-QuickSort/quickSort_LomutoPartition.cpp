// Approach 2  --> Lomuto Partition Algorithm
//  Best Case TC : O(NlogN)   Worst Case TC : O(N^2)  --> when array is already in sorted order
// SC : O(logN)  --> Recursive Tree Space

#include <iostream>
using namespace std;

// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int i = low - 1; // Index of smaller element
    int pivot = arr[high]; // Choosing the last element as the pivot
    
    for (int j = low; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    return i;
}

// Function to perform QuickSort recursively
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Main function
int main() {
    // Sample input 1: Sorting an array of integers in ascending order
    // Input: [5, 2, 9, 1, 3]
    // Output: [1, 2, 3, 5, 9]
    int arr[] = {5, 2, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, n - 1);
    
    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
