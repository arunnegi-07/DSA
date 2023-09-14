// Dynamic Programming --> Tabulation Method
// TC : O(N*sum)  SC : O(N*sum) 

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int perfectSum(int arr[], int n, int sum) {
    int dp[n + 1][sum + 1];

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = 0;
        }
    }

    // Base case: When the sum is zero, there is one way to achieve it (empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the dp table using a bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            // If the current element can be included without exceeding the sum
            if (arr[i - 1] <= j) {
                // Add the ways of including the current element and excluding it
                dp[i][j] = (dp[i - 1][j] % mod + dp[i - 1][j - arr[i - 1]] % mod) % mod;
            } else {
                // If the current element is greater than the current sum, exclude it
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }

    // Return the result stored in the dp table
    return dp[n][sum] % mod;
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
