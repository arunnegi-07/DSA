// Approach 3 : Using Two Pointers Method
// TC : O(N²)  SC : O(1)

// Note : Refer to "Intuition2" file to better understand this approach.

#include <bits/stdc++.h>
using namespace std;

bool findTriplets(int arr[], int n)
{ 
    // Sort the array in ascending order
    sort(arr, arr + n);
    
    // Iterate through the array to find triplets
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;  // Pointer for the second element
        int k = n - 1;  // Pointer for the third element
        
        // Use a two-pointer approach to find the triplet
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];  // Calculate the sum of the triplet
            
            if (sum < 0)
                j++;  // Increment the second pointer for a smaller sum
            else if (sum > 0)
                k--;  // Decrement the third pointer for a larger sum
            else
                return true;  // Triplet with sum zero found
        }
    }
    return false;  // No triplet found
}

int main() {
    // Example inputs
    int arr1[] = {0, -1, 2, -3, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Check for triplets in the first array
    if (findTriplets(arr1, n1))
        cout << "Triplet exists in arr1" << endl;
    else
        cout << "No triplet exists in arr1" << endl;

    // Check for triplets in the second array
    if (findTriplets(arr2, n2))
        cout << "Triplet exists in arr2" << endl;
    else
        cout << "No triplet exists in arr2" << endl;

    return 0;
}

