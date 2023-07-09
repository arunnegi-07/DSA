/* Approach 1 : BruteForce  -->  Sorting the given array and then traversing the array to find the smallest positive missing number.
    TC : O(NlogN)  SC : O(1)

    This approach is straightforward and simple, and it is the first solution that comes to mind when we encounter the problem. 
    However, we can further optimize it to reduce its time complexity to O(N).                                              
                                                                                                                                                                                                                                                                                     */

#include <bits/stdc++.h>
using namespace std;

// Function to find the smallest missing positive number in a sorted array
int missingNumber(int arr[], int n) {
    // Sort the array in ascending order
    sort(arr, arr + n);
        
    int smallestMissing = 1;
    
    // Find the first positive missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] == smallestMissing) {
            smallestMissing++;
        }
    }
    return smallestMissing;
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
