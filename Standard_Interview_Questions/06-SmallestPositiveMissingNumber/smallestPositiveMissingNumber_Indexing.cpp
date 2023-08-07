/* Approach 4 : Indexing with Separation.
    TC : O(N)  SC : O(1)

    This Method is both Time as well as Space Optimized, in this we first separating 'positive number' from '0' and
    'negative numbers' (because our concern is only for positive numbers) and after that we are using indexing method
    to get the smallest missing number.

    Note : Refer to 'Intuition_Indexing' file attached, to get the clear explanation behind this approach.
                                                                                                                                                                                                                                                                                   */    

#include <bits/stdc++.h>
using namespace std;

//Function to find the smallest positive number missing from the array.
int missingNumber(int arr[], int n) {       
    // Separate positive numbers from non-positive numbers
    int positiveIdx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            swap(arr[i], arr[positiveIdx]);
            positiveIdx++;
        }
    }
    
    // Mark elements as negative for positive numbers within range
    for (int i = 0; i < positiveIdx; i++) {
        int index = abs(arr[i]) - 1;
        if (index < positiveIdx && arr[index] > 0) {
            arr[index] = -arr[index];
        }
    }
    
    // Find the index of the first positive number
    for (int i = 0; i < positiveIdx; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }
    
   // If all positive numbers are present, return the next positive number
    return positiveIdx + 1;
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