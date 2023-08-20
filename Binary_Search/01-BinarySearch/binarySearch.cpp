#include <bits/stdc++.h>
using namespace std;

// This function performs a binary search on a sorted integer array 'arr' of size 'n' to find the 'key'.
// It returns the index of 'key' if found, or -1 if 'key' is not in the array.
int binarysearch(int arr[], int n, int key) {
    // Initialize two pointers, 'low' and 'high', to define the search range.
    int low = 0, high = n-1;
    
    // Continue the search until 'low' is less than or equal to 'high'.
    while(low <= high){
        // Calculate the middle index of the current search range.
        int mid = low + (high - low)/2;
        
        // Check if the element at the middle index is equal to the 'key'.
        if(arr[mid] == key){
            // If it is equal, return the index 'mid' as the position of 'key'.
            return mid;
        }
        // If the element at 'mid' is greater than 'key', update 'high' to narrow the search range to the left half.
        else if(arr[mid] > key){
            high = mid - 1;
        }
        // If the element at 'mid' is less than 'key', update 'low' to narrow the search range to the right half.
        else{
            low = mid + 1;
        }
    }
    // If 'key' is not found in the array, return -1 to indicate that it doesn't exist.
    return -1;
}


int main() {
    // Sample input 1: Searching for 5 in a sorted array
    int arr1[] = {1, 3, 5, 7, 9, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int key1 = 5;
    int result1 = binarysearch(arr1, n1, key1);
    
    if (result1 != -1) {
        std::cout << "Sample 1: Element " << key1 << " found at index " << result1 << std::endl;
    } else {
        std::cout << "Sample 1: Element " << key1 << " not found in the array" << std::endl;
    }

    // Sample input 2: Searching for 8 in a sorted array
    int arr2[] = {2, 4, 6, 8, 10, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 8;
    int result2 = binarysearch(arr2, n2, key2);
    
    if (result2 != -1) {
        std::cout << "Sample 2: Element " << key2 << " found at index " << result2 << std::endl;
    } else {
        std::cout << "Sample 2: Element " << key2 << " not found in the array" << std::endl;
    }
    return 0;
}
