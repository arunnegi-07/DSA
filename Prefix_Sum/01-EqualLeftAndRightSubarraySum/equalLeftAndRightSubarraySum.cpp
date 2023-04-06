#include <iostream>
using namespace std;

// Approach 1: Brute Force
// TC : O(N^2)  SC : O(1)

// Function to find the first index in the array such that the sum of elements before it
// is equal to the sum of elements after it.
// If no such index is found, it returns -1.
int equalSum(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        int leftSum = 0, rightSum = 0;
        // Calculate the sum of elements before the current index
        for (int j = 1; j < i; j++) {
            leftSum += A[j];
        }
        // Calculate the sum of elements after the current index
        for (int j = i + 1; j <= n; j++) {
            rightSum += A[j];
        }
        // If the left sum is equal to the right sum, return the current index
        if (leftSum == rightSum) {
            return i;
        }
    }
    // If no such index is found, return -1
    return -1;
}

// Approach 2: Using Prefix Sum
// TC : O(N)  SC : O(N)

// Helper function to calculate Left Sum
int leftSum(int sum_at_index[],int arr[],int i){
    return sum_at_index[i] - arr[i];
}

// Helper function to calculate Right Sum   
int rightSum(int sum_at_index[],int total_sum,int i){
    return total_sum - sum_at_index[i];
}
  
int equalSum(int arr[], int n) {
    // code here
    int sum_at_index[n];
    int sum = 0;
        
    // populating sum_at_index array
    for(int i=0;i<n;i++){
        sum += arr[i];
        sum_at_index[i] = sum; 
    }
        
    int total_sum = sum_at_index[n-1];
        
    for(int i=0;i<n;i++){
        if(leftSum(sum_at_index,arr,i) == rightSum(sum_at_index,total_sum,i))
            return i+1; // If yes, return the current index (since the array is 1-based indexed, add 1 to the index)
    }
    return -1;  // If no index with equal sum is found, return -1
}

// Approach 3: Optimized Version of Approach 2
// TC : O(N)  SC : O(1)

int equalSum(int arr[], int n){
    
    int ans = 0; // Variable to store the index with equal sum
    int total_sum = 0; // Variable to store the total sum of the array
    
    // Calculate the total sum of the array
    for(int i=0;i<n;i++){
        total_sum += arr[i];
    }
        
    int left_sum = 0; // Variable to store the sum of elements to the left of the current index
    int right_sum = total_sum; // Variable to store the sum of elements to the right of the current index
    
    // Iterate through all the elements of the array
    for(int i=0;i<n;i++){
        right_sum -= arr[i]; // Subtract the current element from the sum of elements to the right of the current index
            
        if(left_sum == right_sum) // Check if the sum of elements to the left is equal to the sum of elements to the right
            return i+1; // If yes, return the current index (since the array is 1-based indexed, add 1 to the index)
             
        left_sum += arr[i]; // Add the current element to the sum of elements to the left
    }
    
    // If no index with equal sum is found, return -1
    return -1;
}


int main() {
    int n;

    // Sample input 1
    n = 5;
    int A1[] = {1, 3, 5, 2, 2};
    int index1 = equalSum(A1, n);
    if (index1 == -1) {
        cout << "No such index found for sample input 1\n";
    } else {
        cout << "Index for sample input 1 = " << index1 << endl;
    }

    // Sample input 2
    n = 1;
    int A2[] = {1};
    int index2 = equalSum(A2, n);
    if (index2 == -1) {
        cout << "No such index found for sample input 2\n";
    } else {
        cout << "Index for sample input 2 = " << index2 << endl;
    }

    // Sample input 3
    n = 6;
    int A3[] = {1, 2, 3, 4, 5, 15};
    int index3 = equalSum(A3, n);
    if (index3 == -1) {
        cout << "No such index found for sample input 3\n";
    } else {
        cout << "Index for sample input 3 = " << index3 << endl;
    }

    return 0;
}
