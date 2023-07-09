/* Approach 5 : In-place Swapping 
    TC : O(N)  SC : O(1)

    If you understood the 'appraoch 4' then this approach is very easy for you to understand as the concept behind this
    is very much similar to it.
    Here we are first traversing over the array and for each 'positive' number we are placing it to it's correct position.
    
    After the swapping process is complete, iterate through the modified array again and return the index of the first 
    element that does not satisfy arr[i] = i+1. This index represents the smallest positive missing number because if
    any number is not present at it's correct position it is missing and first such number found is the smallest because
    there may be more than one numbers missing.
    
    Note : Refer to 'Intuition_Swapping' file for more explaination.
                                                                                                                                                                                                                                                                                */
#include <bits/stdc++.h>
using namespace std;

//Function to find the smallest positive number missing from the array. 
int missingNumber(int arr[], int n) { 
    // In-place swapping to arrange positive numbers in their correct positions
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    
    // Find the index of the first element that does not satisfy arr[i] = i+1
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    
    // If all numbers are present, return N+1
    return n + 1;
} 

int main() {
    // Sample input 1
    int arr1[] = {1, 2, 3, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Smallest missing positive number: " << missingNumber(arr1, n1) << endl;
    
    // Sample input 2
    int arr2[] = {2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Smallest missing positive number: " << missingNumber(arr2, n2) << endl;
    
    return 0;
}