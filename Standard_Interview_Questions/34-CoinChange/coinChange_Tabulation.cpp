// Approach 3 :  Dynamic Programming  --> Tabulation Method 
// TC : O(N*Sum)   SC : O(N*Sum) 

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to make a sum 'sum' using coins from the given array.
// The function considers the first 'N' coins in the array.
long long int count(int coins[], int N, int sum) {
    // Create a 2D dp table 'dp' to store the counts of combinations for subproblems.
    vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));
    
    // Initialize base cases:
    // - There is only one way to make a sum of 0, using no coins.
    for (int i = 0; i < N; i++) {
        dp[i][0] = 1;
    }
    
    // For the first coin, there is a combination for every multiple of its value up to 'sum'.
    for (int i = 0; i <= sum; i++) {
        dp[0][i] = (i % coins[0] == 0);
    }
    
    // Iterate through all remaining coins and sum values to fill the dp table.
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= sum; j++) {
            // Calculate the number of combinations by considering two possibilities:
            // 1. Taking the current coin and considering the remaining sum.
            // 2. Not taking the current coin and using the combinations from the previous coin.
            long long int taken = 0;
            if (coins[i] <= j) {
                taken = dp[i][j - coins[i]];
            }
            long long int notTaken = dp[i - 1][j];
            
            // Store the total number of combinations for the current subproblem.
            dp[i][j] = taken + notTaken;
        }
    }
    
    // The value at dp[N-1][sum] contains the total number of combinations to make the sum using all coins.
    return dp[N - 1][sum];
}

int main() {
    // Sample input
    int coins[] = {1, 2, 3};
    int N = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;

    cout << "Number of ways to make sum " << sum << " using given coins: "
         << count(coins, N, sum) << endl;
    
    return 0;
}
