// Approach 3 : Using maxHeap
// TC : O(N*logN)   SC : O(N)

// We are using maxHeap because everytime we want maximum element after updation at each step and we know maxHeap
// everytime after new insertion shifts maxElement at top, so this property of maxHeap become useful for us.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum sum of diamonds
long long maxDiamonds(int arr[], int N, int K) {
    priority_queue<int> maxHeap; // Create a max heap
    
    // Insert all elements of the array into the max heap
    // This will take O(NlogN)
    for(int i = 0; i < N; i++) {
        maxHeap.push(arr[i]);
    }
    
    long long ans = 0; // Variable to store the maximum sum of diamonds
    
    // Perform K iterations
    for(int i = 0; i < K; i++) {
        int val = maxHeap.top(); // Get the maximum element from the max heap
        ans += val; // Add the maximum element to the sum
        maxHeap.pop(); // Remove the maximum element from the max heap
        maxHeap.push(val / 2); // Insert the updated element (divided by 2) back into the max heap
        
        // Note: The updated element is inserted into the max heap, and it will be considered as the maximum in the next iteration.
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
