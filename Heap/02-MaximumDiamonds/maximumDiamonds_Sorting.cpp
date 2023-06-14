// Approach 2 : Using Sorting
// TC : O(K*NlogN)   SC : O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum sum of diamonds
long long maxDiamonds(int arr[], int N, int K) {
    long long ans = 0; // Variable to store the maximum sum of diamonds
    
    for(int i = 0; i < K; i++) {

        // This will take O(NlogN)
        sort(arr, arr + N, greater<int>()); // Sort the array in descending order
        
        ans += arr[0]; // Add the maximum element to the sum
        arr[0] = arr[0] / 2; // Divide the maximum element by 2
        
        // Note: The maximum element is modified in each iteration, and the modified value will be considered in the next iteration.
    }
    
    return ans; // Return the maximum sum of diamonds
}

int main() {
    // Sample inputs
    int arr1[] = {4, 2, 8, 5};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int K1 = 3;
    
    int arr2[] = {1, 6, 3, 10, 5};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    int K2 = 4;
    
    // Calculate the maximum sum of diamonds for the first sample input
    long long maxSum1 = maxDiamonds(arr1, N1, K1);
    cout << "Maximum sum of diamonds for sample input 1: " << maxSum1 << endl;
    
    // Calculate the maximum sum of diamonds for the second sample input
    long long maxSum2 = maxDiamonds(arr2, N2, K2);
    cout << "Maximum sum of diamonds for sample input 2: " << maxSum2 << endl;
    
    return 0;
}