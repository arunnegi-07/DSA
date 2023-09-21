// Dynamic Programming --> Memoization
// TC : O(N)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;  

//Function to find the maximum money the thief can get.
int maxMoney(int arr[], int n, int currentIndex, unordered_map<int, int>& memo) {
    // Base case: If there are no more houses to consider, return 0.
    if (currentIndex >= n) {
        return 0;
    }

    // Check if the result for the current index is already memoized.
    if (memo.find(currentIndex) != memo.end()) {
        return memo[currentIndex];
    }

    // Case 1: Rob the current house and skip the next one.
    int stealCurrent = arr[currentIndex] + maxMoney(arr, n, currentIndex + 2, memo);

    // Case 2: Skip the current house.
    int skipCurrent = maxMoney(arr, n, currentIndex + 1, memo);

    // Store the maximum of the two cases in the memoization table.
    memo[currentIndex] = max(stealCurrent, skipCurrent);

    return memo[currentIndex];
}

int FindMaxSum(int arr[], int n) {
    // Initialize the memoization table.
    unordered_map<int, int> memo;

    // Call the recursive function starting from the first house (index 0).
    return maxMoney(arr, n, 0, memo);
}
    
int main() {
    // Test case 1
    int arr1[] = {6, 5, 5, 7, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1 = FindMaxSum(arr1, n1);
    cout << "Test Case 1: " << result1 << endl;

    // Test case 2
    int arr2[] = {1, 5, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = FindMaxSum(arr2, n2);
    cout << "Test Case 2: " << result2 << endl;

    return 0;
}