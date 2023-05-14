// Approach : Dynamic Programming --> Memoization
// TC : N*k*target   SC : O(k*target) + O(k) extra stack space

#include<bits/stdc++.h>
using namespace std;

bool solve(int N, int K, int target, vector<int> &coins, vector<vector<int>> &dp) {
            
    // If we have used up all K coins and the target sum is 0, return true
    if (K == 0 and target == 0) return true;
        
    // If the current subproblem has already been solved, return the answer
    if (dp[K][target] != -1) return dp[K][target];
        
    bool ans = false;
    // For each coin, if it can be used and there are still more coins left, try using it to reach the target sum
    for (int i = 0; i < N; i++) {
        if(target>=coins[i] and K-1>=0)
            ans |= solve(N, K - 1, target - coins[i], coins, dp);
    }
        
    // Memoize the answer for the current subproblem
    return dp[K][target] = ans;
}
    
// Function to solve the problem using memoization
bool makeChanges(int N, int K, int target, vector<int> &coins) {
    // Create a 2D vector to store the solutions to subproblems
    vector<vector<int>> dp(K+1, vector<int>(target+1, -1));
    // Call the recursive function to solve the problem
    return solve(N, K, target, coins, dp);
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