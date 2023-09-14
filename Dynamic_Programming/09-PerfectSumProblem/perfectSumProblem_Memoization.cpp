// Dynamic Programming --> Memoization
// TC : O(N*sum)  SC : O(N*sum) 

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// Recursive function with memoization to count subsets with a given sum
int f(int i, int n, int arr[], int sum, vector<vector<int>>& dp) {
    // Base case: If we have processed all elements (i == n)
    if (i == n) {
        // If the desired sum is achieved, return 1 (found a valid subset)
        if (sum == 0)
            return 1;
        // Otherwise, return 0 (subset does not achieve the desired sum)
        else
            return 0;
    }

    // If the result for the current state (i, sum) is already computed, return it
    if (dp[i][sum] != -1)
        return dp[i][sum];

    int pick = 0, notPick;

    // Check if the current element can be included in the subset without exceeding the sum
    if (arr[i] <= sum) {
        // Include the current element and move to the next element
        pick = f(i + 1, n, arr, sum - arr[i], dp);
    }

    // Exclude the current element and move to the next element
    notPick = f(i + 1, n, arr, sum, dp);

    // Store the result in the dp table and take modulo to handle large values
    return dp[i][sum] = (pick % mod + notPick % mod) % mod;
}

int perfectSum(int arr[], int n, int sum) {
    // Initialize a 2D dp array with -1 values to store results of subproblems
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    // Start the recursive function from the first element (i=0) and return the result
    return f(0, n, arr, sum, dp);
}


int main() {
    int arr1[] = {2, 3, 5, 6, 8, 10};
    int N1 = 6;
    int sum1 = 10;

    int result1 = perfectSum(arr1, N1, sum1);
    cout << "Result 1: " << result1 << endl;

    int arr2[] = {1, 2, 3, 4, 5};
    int N2 = 5;
    int sum2 = 10;

    int result2 = perfectSum(arr2, N2, sum2);
    cout << "Result 2: " << result2 << endl;

    return 0;
}
