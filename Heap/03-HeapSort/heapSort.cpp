// TC : O(NlogN)  SC : O(1)  --> as doing inplace sorting

#include <iostream>
using namespace std;

// Heapify function to maintain the heap property.
void heapify(int arr[], int n, int i) {
    int leftChildIndex = i * 2 + 1;
    int rightChildIndex = i * 2 + 2;
    int largest = i;

    // Find the index of the largest element among the current node, left child, and right child.
    if (leftChildIndex < n && arr[largest] < arr[leftChildIndex]) {
        largest = leftChildIndex;
    }

    if (rightChildIndex < n && arr[largest] < arr[rightChildIndex]) {
        largest = rightChildIndex;
    }

    // If the value of largest is updated, we need to make a swap
    // and then maintain the heap property, so we call heapify for that largest value.
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a Max Heap from an array.
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify all nodes in reverse order.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to sort an array using Heap Sort.
void heapSort(int arr[], int n) {
    // Build MaxHeap from the given array.
    buildHeap(arr, n);

    // Extract elements one by one from the heap.
    for (int i = n - 1; i > 0; i--) {
        // Move the current root (largest element) to the end.
        swap(arr[0], arr[i]);

        // Reduce the heap size and heapify the root to maintain the heap property.
        heapify(arr, i, 0);
    }
}

// Function to print the elements of the array.
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Sample input 1
    int arr1[] = {4, 1, 3, 9, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original array 1: ";
    printArray(arr1, n1);

    heapSort(arr1, n1);

    cout << "Sorted array 1: ";
    printArray(arr1, n1);

    // Sample input 2
    int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Original array 2: ";
    printArray(arr2, n2);

    heapSort(arr2, n2);

    cout << "Sorted array 2: ";
    printArray(arr2, n2);

    return 0;
}
