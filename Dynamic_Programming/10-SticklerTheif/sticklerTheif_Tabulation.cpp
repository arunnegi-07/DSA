// Dynamic Programming --> Tabulation Method
// TC : O(N)  SC : O(N)

#include <bits/stdc++.h>
using namespace std;

//Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    return dp[n - 1];
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