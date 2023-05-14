// Approach : Dynamic Programming --> Tabulation
// TC : N*k*target   SC : O(k*target)

#include<bits/stdc++.h>
using namespace std;

bool makeChanges(int N, int K, int target, vector<int> coins) {
    // Create a 2D boolean array to store the subproblem solutions
    bool dp[K + 1][target + 1];
    // Initialize all entries to false
    memset(dp, false, sizeof(dp));
    // Base case: when no coins are picked and the target sum is zero, the answer is true
    dp[0][0] = true;
    // Iterate through each number of coins picked
    for (int i = 1; i < K + 1; i++) {
        // Iterate through each possible target sum
        for (int j = 1; j < target + 1; j++) {
            // Iterate through each coin denomination
            for (int k = 0; k < N; k++) {
                // If the current coin denomination is greater than the current target sum, skip it
                if (j < coins[k]) continue;
                // Update the current solution by checking if there exists a solution with one less coin
                // and a target sum reduced by the value of the current coin denomination
                dp[i][j] |= dp[i - 1][j - coins[k]];
            }
        }
    }
    // Return the final solution, which is in the last cell of the DP table
    return dp[K][target];
} 


  
int main() {
    // Sample input 1
    int n = 5, k = 3, target = 11;
    vector<int> coins = {1, 10, 5, 8, 6};
    if (makeChanges(n, k, target, coins)) {
        cout << "Possible to make change of " << target << " cents using exactly " << k << " coins." << endl;
    } else {
        cout << "Not possible to make change of " << target << " cents using exactly " << k << " coins." << endl;
    }

    // Sample input 2
    int m = 3, p = 5, q = 25;
    vector<int> c = {7, 2, 4};
    if (makeChanges(m, p, q, c)) {
        cout << "Possible to make change of " << q << " cents using exactly " << p << " coins." << endl;
    } else {
        cout << "Not possible to make change of " << q << " cents using exactly " << p << " coins." << endl;
    }
    return 0;
}